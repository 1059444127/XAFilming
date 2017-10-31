using System;
using System.Collections.Generic;
using UIH.Mcsf.Core;
using UIH.XA.Core;
using UIH.XA.GlobalParameter;

namespace UIH.XA.Filming.CommandSenderSimulator
{
    public class FilmingCommandSenderSimulatorContainee : CLRContaineeBase
    {
        private readonly Dictionary<int, Action<int>> _actionDictionary = new Dictionary<int, Action<int>>();

        /// <inheritdoc />
        public override void Startup()
        {
            this.LogDevInfo("StartUp");
            _actionDictionary.Add(CommunicationCommandID.COMMAND_ID_PRINT, SendPrintCommand);
            _actionDictionary.Add(CommunicationCommandID.COMMAND_ID_FILMING, SendFilmFilesCommand);
        }

        private void SendFilmFilesCommand(int commandID)
        {
            var commandText = new CommandContext();
            commandText.iCommandId = commandID;
            commandText.sReceiver = CommunicationNode.FilmingService; 
            commandText.sStringObject = @"E:\1.dcm|E:\2.dcm|E:\1.dcm|E:\2.dcm";
            commandText.pCommandCallback = new PrintCommandCallBack();

            var proxy = GetCommunicationProxy();
            var result = proxy.AsyncSendCommand(commandText);
            this.LogDevInfo(string.Format("SendFilmFilesComand send result is {0}", result));
        }


        /// <inheritdoc />
        public override void DoWork()
        {
            if (0 != SendSystemEvent("", (int)CLRContaineeEventId.SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY, GetCommunicationProxy().GetName()))
            {
                this.LogDevInfo("The event send to System manager fail,Please restart the FilmingFEContainee");
            }
            this.LogDevInfo("has informed system manager that FilmingViewer is up");

            while (true)
            {
                this.LogDevInfo("Press any key to continue");
                Console.ReadKey();

                SendCommand(CommunicationCommandID.COMMAND_ID_FILMING);
                //SendCommand(CommunicationCommandID.COMMAND_ID_PRINT);
            }
        }

        private void SendCommand(int commandID)
        {
            if(_actionDictionary.ContainsKey(commandID)) _actionDictionary[commandID].Invoke(commandID);
            else
                this.LogDevInfo(string.Format("Non Action for command [{0}]", commandID));
        }


        private void SendPrintCommand(int commandID)
        {
            var commandText = new CommandContext();
            commandText.iCommandId = commandID;
            commandText.sReceiver = CommunicationNode.Filming;
            commandText.sStringObject = @"E:\1.dcm|E:\2.dcm|E:\1.dcm|E:\2.dcm";
            commandText.pCommandCallback = new PrintCommandCallBack();

            var proxy = GetCommunicationProxy();
            var result = proxy.AsyncSendCommand(commandText);
            this.LogDevInfo(string.Format("Command Result : [{0}]", result));
        }
    }
}