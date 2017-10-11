using System;
using System.Collections.Generic;
using UIH.Mcsf.Core;
using UIH.XA.GlobalParameter;

namespace UIH.XA.Filming.CommandSenderSimulator
{
    public class FilmingCommandSenderSimulatorContainee : CLRContaineeBase
    {
        private Dictionary<int, Action<int>> _actionDictionary = new Dictionary<int, Action<int>>();

        /// <inheritdoc />
        public override void Startup()
        {
            Console.WriteLine("StartUp");
            _actionDictionary.Add(CommunicationCommandID.COMMAND_ID_PRINT, SendPrintCommand);
        }

        //TODO: Move containee & log configure file to project directory

        /// <inheritdoc />
        public override void DoWork()
        {
            if (0 != SendSystemEvent("", (int)CLRContaineeEventId.SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY, GetCommunicationProxy().GetName()))
            {
                Console.WriteLine("The event send to System manager fail,Please restart the FilmingFEContainee");
            }
            Console.WriteLine("has informed system manager that FilmingViewer is up");

            while (true)
            {
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();

                SendCommand(CommunicationCommandID.COMMAND_ID_PRINT);
            }
        }

        private void SendCommand(int commandID)
        {
            if(_actionDictionary.ContainsKey(commandID)) _actionDictionary[commandID].Invoke(commandID);
            else
                Console.WriteLine("Non Action for command [{0}]", commandID);
        }


        private void SendPrintCommand(int commandID)
        {
            var commandText = new CommandContext();
            commandText.iCommandId = commandID;
            commandText.sReceiver = "XAFilmingService@@";
            commandText.sStringObject = @"E:\1.dcm|E:\2.dcm|E:\1.dcm|E:\2.dcm";
            commandText.pCommandCallback = new PrintCommandCallBack();

            var proxy = GetCommunicationProxy();
            var result = proxy.AsyncSendCommand(commandText);
            Console.WriteLine("Command Result : [{0}]", result);
        }
    }
}