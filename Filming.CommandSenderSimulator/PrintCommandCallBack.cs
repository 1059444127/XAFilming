using System;
using UIH.Mcsf.Core;
using UIH.XA.Core;
using IAsyncResult = UIH.Mcsf.Core.IAsyncResult;

namespace UIH.XA.Filming.CommandSenderSimulator
{
    class PrintCommandCallBack : ICommandCallbackHandler
    {
        /// <inheritdoc />
        public override int HandleReply(IAsyncResult pAsyncResult)
        {
            this.LogDevInfo(string.Format("Reply is : [{0}]", pAsyncResult.GetStringObject()));
            return base.HandleReply(pAsyncResult);
        }
    }
}
