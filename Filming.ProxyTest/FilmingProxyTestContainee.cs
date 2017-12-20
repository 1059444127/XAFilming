using UIH.Mcsf.Core;
using UIH.XA.Core;

namespace UIH.XA.Filming.ProxyTest
{
    public class FilmingProxyTestContainee : CLRContaineeBase
    {
        public override void DoWork()
        {
            const string configPath = @"..\..\IAS\MiddleWare\Filming\\Filming.ProxyTest\Config\FilmingProxyTestBoot.xml";
            var app = new XApp(configPath, GetCommunicationProxy());

            app.Run();
        }
    }
}
