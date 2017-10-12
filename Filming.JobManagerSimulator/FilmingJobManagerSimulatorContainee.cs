using System;
using System.Threading;
using System.Windows.Threading;
using UIH.Mcsf.Core;

namespace UIH.XA.Filming.JobManagerSimulator
{
    public class FilmingJobManagerSimulatorContainee : CLRContaineeBase
    {
        /// <inheritdoc />
        public override void Startup()
        {
            Console.WriteLine("StartUp");


            var thread = new Thread(ShowWindow);
            thread.SetApartmentState(ApartmentState.STA);   //UI thread must be STA
            thread.Start();
        }

        private void ShowWindow()
        {
            var window = new JobManagerWindow();
            window.ShowDialog();                            //Should Be ShowDialog, not Show
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

        }


    }
}
