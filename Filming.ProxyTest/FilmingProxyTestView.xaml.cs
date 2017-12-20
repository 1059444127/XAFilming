using System.ComponentModel.Composition;

namespace UIH.XA.Filming.ProxyTest
{
    /// <summary>
    /// Interaction logic for FilmingProxyTestView.xaml
    /// </summary>
     
    [Export("FilmingProxyTestView")]
    public partial class FilmingProxyTestView
    {
        public FilmingProxyTestView()
        {
            InitializeComponent();
        }
    }
}
