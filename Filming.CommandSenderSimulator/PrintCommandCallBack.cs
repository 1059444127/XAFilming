using System;
using UIH.Mcsf.Core;
using IAsyncResult = UIH.Mcsf.Core.IAsyncResult;

namespace UIH.XA.Filming.CommandSenderSimulator
{
    class PrintCommandCallBack : ICommandCallbackHandler
    {
        /// <inheritdoc />
        public override int HandleReply(IAsyncResult pAsyncResult)
        {
            Console.WriteLine("Reply is : [{0}]", pAsyncResult.GetStringObject());
            return base.HandleReply(pAsyncResult);
        }
    }
}
