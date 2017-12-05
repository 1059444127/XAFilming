using System;
using System.ComponentModel.Composition;
using System.Text;
using UIH.Mcsf.Database;
using UIH.Mcsf.Pipeline.Data;
using UIH.Mcsf.Pipeline.Dictionary;
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

        public void Print(DicomAttributeCollection dataHeader)
        {
            this.LogDevInfo("Begin to print DataHeader");
            try
            {
                byte[] serializedObject;
                if (!dataHeader.Serialize(out serializedObject))
                {
                    this.LogDevError("Fail to serialize dataHeader");
                    return;
                }

                this.LogDevInfo("Succeed to seriealize dataHeader");
                _communicator.AsyncSendCommand(CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADER, CommunicationNode.FilmingService, serializedObject);
                this.LogDevInfo(string.Format("Command [{0}] sent with a serialized dataHeader", CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADER));
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

                int dataHeaderIndex = 1;
                int dataHeaderCount = dataHeaders.Length;
                foreach (var dataHeader in dataHeaders)
                {
                    string packetHeader = string.Join(CommunicationCommandID.ParameterListSeparator, jobID,
                        dataHeaderIndex.ToString(), dataHeaderCount.ToString());
                    var packetHeaderBytes = Encoding.UTF8.GetBytes(string.Format("{0}{1}{2}", packetHeader, CommunicationCommandID.ParameterListSeparator, CommunicationCommandID.ParameterListSeparator));

                    dataHeader.InsertElement(PacketHeaderTag, packetHeaderBytes);
                    //dataHeader.InsertElement((uint)Tag.SeriesInstanceUid, jobID);
                    //dataHeader.InsertElement((uint)Tag.InstanceNumber, dataHeaderIndex.ToString());
                    //dataHeader.InsertElement(PacketHeaderTag, dataHeaderCount.ToString());
                    //dataHeader.InsertElement(PacketHeaderTag, packetHeader);

                    byte[] serializedDataheader;
                    if (!dataHeader.Serialize(out serializedDataheader))
                    {
                        this.LogDevError(string.Format("Fail to serialize dataHeader [{0}]", dataHeaderIndex));
                        return;
                    }

                    byte[] serializedObject = MergeByteArray(packetHeaderBytes, serializedDataheader);

                    this.LogDevInfo(string.Format("Succeed to seriealize dataHeader [{0}]", dataHeaderIndex++));
                    _communicator.AsyncSendCommand(CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADERS, CommunicationNode.FilmingService, serializedObject);
                    this.LogDevInfo(string.Format("Command [{0}] sent with a serialized dataHeader", CommunicationCommandID.COMMAND_ID_FILMING_DATAHEADER));
                }
            }
            catch (Exception e)
            {
                this.LogException(e);
            }
        }

        private string GetJobID()
        {
            return DateTime.Now.ToLongTimeString();
        }

        /// <summary>
        /// merge two byte[] to one byte[]
        /// </summary>
        /// <param name="a">byte[] a</param>
        /// <param name="b">byte[] b</param>
        /// <returns>byte[] c</returns>
        private byte[] MergeByteArray(byte[] a, byte[] b)
        {
            if (null == a || null == b)
            {
                throw new global::System.InvalidOperationException("MergeByteArray byte[] object is null!");
            }

            // new byte[] to load byte[] a and byte[] b
            byte[] c = new byte[a.Length + b.Length];
            using (System.IO.Stream s = new System.IO.MemoryStream())
            {
                // write byte[] to stream
                s.Write(a, 0, a.Length);
                s.Write(b, 0, b.Length);

                // reinitialize position of stream
                s.Position = 0;
                // read byte[] from stream
                if (s.Read(c, 0, c.Length) > 0)
                {
                    return c;
                }
                else
                {
                    return null;
                }
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

        public static void InsertElement(this DicomAttributeCollection dataHeader, uint tag, string value)
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
            if (!element.SetString(0, value))
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


