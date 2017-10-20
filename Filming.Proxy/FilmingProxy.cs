using System;
using System.ComponentModel.Composition;
using UIH.Mcsf.Pipeline.Data;
using UIH.XA.Core;
using UIH.XA.Filming.Interface;
using UIH.XA.GlobalParameter;

namespace UIH.XA.Filming.Proxy
{
    [Export(typeof(IFilming))]
    public class FilmingProxy : IFilming
    {
        [Import] private ICommunicator _communicator;

        public void Print(params string[] paths)
        {
            try
            {
                var serializedPaths = string.Join(CommunicationCommandID.ParameterListSeparator, paths);
                this.LogDevInfo(string.Format("Film {0}", serializedPaths));
 
                _communicator.AsyncSendCommand(CommunicationCommandID.COMMAND_ID_FILMING, CommunicationNode.FilmingService ,serializedPaths);
                this.LogDevInfo(string.Format("Command [{0}] sent with message [{1}]",
                    CommunicationCommandID.COMMAND_ID_FILMING, serializedPaths));
            }
            catch (Exception e)
            {
                this.LogException(e);
            }
        }

        public void Print(params DicomAttributeCollection[] dataHeaders)
        {
            try
            {
                this.LogDevInfo("Begin to print DataHeaders");
                int dataHeaderIndex = 0;
                foreach (var dataHeader in dataHeaders)
                {
                    // TODO-Film-MayBe: 私有 Tag 添加任务信息
                    byte[] serializedObject;
                    if (!dataHeader.Serialize(out serializedObject))
                    {
                        this.LogDevInfo(string.Format("Fail to serialize dataHeader [{0}]", dataHeaderIndex++));
                        continue;
                    }

                    this.LogDevInfo(string.Format("Succeed to seriealize dataHeader [{0}]", dataHeaderIndex++));
                    _communicator.AsyncSendCommand(CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADER, CommunicationNode.FilmingService, serializedObject);
                    this.LogDevInfo(string.Format("Command [{0}] sent with a serialized dataHeader", CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADER));
                }
            }
            catch (Exception e)
            {
                this.LogException(e);
            }
        }
    }
}
