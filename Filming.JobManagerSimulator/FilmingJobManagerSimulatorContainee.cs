using System;
using UIH.Mcsf.Core;

namespace UIH.XA.Filming.JobManagerSimulator
{
    public class FilmingJobManagerSimulatorContainee : CLRContaineeBase
    {
        /// <inheritdoc />
        public override void Startup()
        {
            Console.WriteLine("StartUp");
        }


        /// <inheritdoc />
        public override void DoWork()
        {
            if (0 != SendSystemEvent("", (int)CLRContaineeEventId.SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY, GetCommunicationProxy().GetName()))
            {
                Console.WriteLine("The event send to System manager fail,Please restart the FilmingFEContainee");
            }
            Console.WriteLine("has informed system manager that FilmingViewer is up");

        }


    }
}
