using System;
using System.ComponentModel.Composition;
using System.Text;
using UIH.Mcsf.Database;
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

        private const uint PacketHeaderTag = 0X00613102;

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

                var uidManager = McsfDatabaseDicomUIDManagerFactory.Instance().CreateUIDManager();
                var jobID = uidManager.CreateSeriesUID(string.Empty);

                int dataHeaderIndex = 0;
                int dataHeaderCount = dataHeaders.Length;
                foreach (var dataHeader in dataHeaders)
                {
                    string packetHeader = string.Join(CommunicationCommandID.ParameterListSeparator, jobID,
                        dataHeaderIndex.ToString(), dataHeaderCount.ToString());
                    var packetHeaderBytes = Encoding.UTF8.GetBytes(packetHeader);

                    dataHeader.InsertElement(PacketHeaderTag, packetHeaderBytes);


                    byte[] serializedObject;
                    if (!dataHeader.Serialize(out serializedObject))
                    {
                        this.LogDevError(string.Format("Fail to serialize dataHeader [{0}]", dataHeaderIndex));
                        return;
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

    static class DicomAttributeCollectionExtension
    {
        public static void InsertElement(this DicomAttributeCollection dataHeader, uint tag, byte[] value)
        {
            var type = typeof(DicomAttributeCollectionExtension);

            if (dataHeader.Contains(tag))
            {
                dataHeader.RemoveDicomAttribute(tag);
                type.LogDevInfo(string.Format("Removed old element with tag [{0}]", tag));
            }
            var element = DicomAttribute.CreateAttribute(tag);
            if (null == element)
            {
                type.LogDevWarning(string.Format("Failed to Create Dicom Attribute for tag [{0}] ",
                    tag));
                return;
            }
            if (!element.SetBytes(0, value))
            {
                type.LogDevWarning(
                    string.Format("Failed to insert element [{0}] with tag [{1}]", value, tag));
                return;
            }

            type.LogDevInfo(
                string.Format("Succeeded to insert element [{0}] with tag [{1}]", value, tag));
        }
    }
}


