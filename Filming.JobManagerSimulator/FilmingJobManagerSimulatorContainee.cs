using System;
using System.Threading;
using UIH.Mcsf.Core;
using UIH.XA.Filming.ViewMock;

namespace UIH.XA.Filming.JobManagerSimulator
{
    public class FilmingJobManagerSimulatorContainee : CLRContaineeBase
    {
        private JobManagerWindow _jobManagerWindow;

        /// <inheritdoc />
        public override void Startup()
        {
            Console.WriteLine("StartUp");

            var proxy = GetCommunicationProxy();
            proxy.RegisterCommandHandler((int)Mcsf.JobManager.JobManagerCommunicationID.ToMainFrameCmd, (StringCmdHandler)HandleCommand);  
        }

        private string HandleCommand(CommandContext commandContext)
        {
            //TODO: convert commandContext to JobCollectionViewModel

            var jobs = new JobCollectionViewModel();
            _jobManagerWindow.DataContext = jobs;

            return string.Empty;
        }

        private void ShowWindow()
        {
            _jobManagerWindow = new JobManagerWindow();
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
