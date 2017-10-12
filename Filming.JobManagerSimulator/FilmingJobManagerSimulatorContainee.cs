using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Threading;
using UIH.Mcsf.Core;
using UIH.Mcsf.JobManager;
using UIH.XA.Filming.ViewMock;

namespace UIH.XA.Filming.JobManagerSimulator
{
    public class FilmingJobManagerSimulatorContainee : CLRContaineeBase
    {
        private JobManagerWindow _jobManagerWindow;
        private JobCollectionViewModel _jobCollectionViewModel;

        /// <inheritdoc />
        public override void Startup()
        {
            Console.WriteLine("StartUp");

            var proxy = GetCommunicationProxy();
            proxy.RegisterCommandHandler((int)Mcsf.JobManager.JobManagerCommunicationID.ToMainFrameCmd, (StringCmdHandler)HandleCommand);  
        }

        private string HandleCommand(CommandContext commandContext)
        {
            Console.WriteLine("Received command from [{0}]", commandContext.sReceiver);

            var jobManagerInfoWrapper = new JobManagerInfoWrapper();
            jobManagerInfoWrapper.Deserialize(commandContext.sSerializeObject);
            var jobManagerInfoList = jobManagerInfoWrapper.GetJobManagerInfoList();

            FillJobCollectionViewModelWith(jobManagerInfoList);

            return string.Empty;
        }

        private void FillJobCollectionViewModelWith(List<JobManagerInfo> jobManagerInfoList)
        {
            var jobCollection = _jobCollectionViewModel.JobCollection;
            _jobManagerWindow.Dispatcher.Invoke(new Action(() => jobCollection.Clear()));

            foreach (var jobManagerInfo in jobManagerInfoList)
            {
                var job = new JobViewModel();
                job.ID = jobManagerInfo.Jobitemid;
                job.Progress = jobManagerInfo.Progress;
                job.Status = jobManagerInfo.Jobitemstatus.ToString();

                _jobManagerWindow.Dispatcher.Invoke(new Action(() => jobCollection.Add(job)));
            }
        }

        private void ShowWindow()
        {
            _jobManagerWindow = new JobManagerWindow();
            _jobCollectionViewModel = new JobCollectionViewModel();
            _jobCollectionViewModel.JobCollection.Add(new JobViewModel() { ID = "SampleID", Progress = "SampleProgress", Status = "SampleStatus" });

           
            _jobManagerWindow.DataContext = _jobCollectionViewModel;
            _jobManagerWindow.ShowDialog();                            //Should Be ShowDialog, not Show
        }


        /// <inheritdoc />
        public override void DoWork()
        {
            Console.WriteLine("DoWork");
            if (0 != SendSystemEvent("", (int)CLRContaineeEventId.SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY, GetCommunicationProxy().GetName()))
            {
                Console.WriteLine("The event send to System manager fail,Please restart the FilmingFEContainee");
            }
            Console.WriteLine("has informed system manager that FilmingViewer is up");

            var thread = new Thread(ShowWindow);
            thread.SetApartmentState(ApartmentState.STA);   //UI thread must be STA
            thread.Start();

        }


    }
}
