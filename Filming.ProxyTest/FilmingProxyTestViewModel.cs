using System.ComponentModel.Composition;
using System.Windows;
using System.Windows.Input;
using UIH.XA.Common.MVVM;
using UIH.XA.Filming.Interface;

namespace UIH.XA.Filming.ProxyTest
{
    [Export("FilmingProxyTestViewModel")]
    class FilmingProxyTestViewModel : NotificationObject
    {
        private IPrint _printProxy;

        [ImportingConstructor]
        public FilmingProxyTestViewModel(IPrint printProxy)
        {
            _printProxy = printProxy;
        }

        #region [--FastPrintCommand--]

        private ICommand _fastPrintCommand;

        public ICommand FastPrintCommand
        {
            get { return _fastPrintCommand = _fastPrintCommand ?? new RelayCommand<object>(FastPrint); }
        }

        private void FastPrint(object obj)
        {
            var visual = obj as FrameworkElement;
            if (null != visual)
            {
                _printProxy.Print(visual);
            }
        }

        #endregion [--FastPrintCommand--]    

    }
}
