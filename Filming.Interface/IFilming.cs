using UIH.Mcsf.Pipeline.Data;

namespace UIH.XA.Filming.Interface
{
    public interface IFilming
    {
        void Print(params string[] paths);
        void Print(params DicomAttributeCollection[] dataHeaders);
    }
}