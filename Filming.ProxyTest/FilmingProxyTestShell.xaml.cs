using System.ComponentModel.Composition;
using UIH.XA.Core;

namespace UIH.XA.Filming.ProxyTest
{
    /// <summary>
    /// Interaction logic for FilmingProxyTestShell.xaml
    /// </summary>
    
    [Export("FilmingProxyTestShell", typeof(IShell))]
    public partial class FilmingProxyTestShell
    {
        public FilmingProxyTestShell()
        {
            InitializeComponent();
        }
    }
}
