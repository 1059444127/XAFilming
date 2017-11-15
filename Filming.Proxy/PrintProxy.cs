using System;
using System.ComponentModel.Composition;
using System.Linq;
using System.Printing;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using UIH.XA.Core;
using UIH.XA.Filming.Interface;

namespace UIH.XA.Filming.Proxy
{
    [Export(typeof(IPrint))]
    public class PrintProxy : IPrint
    {
        /// <inheritdoc />
        public void Print(FrameworkElement visual)
        {
            this.LogDevInfo("Begin to Print");
            GetPrintDialog();

            try
            {
                var printRect = GetPrintRect(new Size(visual.ActualWidth, visual.ActualHeight));
                var visualBrush = new VisualBrush(visual);
                var drawingVisual = new DrawingVisual();
                using (DrawingContext context = drawingVisual.RenderOpen())
                {
                    context.DrawRectangle(visualBrush, new Pen(visualBrush, 0), printRect); 
                }

                _printDialog.PrintVisual(drawingVisual, DateTime.Now.ToLongTimeString());
                this.LogDevInfo("End to Print");
            }
            catch (Exception e)
            {
                this.LogException(e, "Failed to print");
            }
        }


        private Rect GetPrintRect(Size printObjectSize)
        {
            var printDestinationSize = new Size(_printDialog.PrintableAreaWidth, _printDialog.PrintableAreaHeight);
            var printSize = CalculatePrintSize(printObjectSize, printDestinationSize);
            var printPoint = new Point((printDestinationSize.Width - printSize.Width) / 2,
                (printDestinationSize.Height - printSize.Height) / 2);
            return new Rect(printPoint, printSize);
        }


        private PrintDialog _printDialog;

        private Size CalculatePrintSize(Size printObjectSize, Size printDestinationSize)
        {
            return printObjectSize.IsThinThan(printDestinationSize)
                ? new Size(printObjectSize.Width * printDestinationSize.Height / printObjectSize.Height, printDestinationSize.Height)
                : new Size(printDestinationSize.Width, printObjectSize.Height * printDestinationSize.Width / printObjectSize.Width);
        }

        private void GetPrintDialog()
        {
            var localPrintServer = new LocalPrintServer();
            var localPrinterQueueCollection = localPrintServer.GetPrintQueues();
            var printerQueue = localPrinterQueueCollection.FirstOrDefault();
            PrintTicket printTicket = null;
            if (null != printerQueue) printTicket = printerQueue.DefaultPrintTicket;

            _printDialog = new PrintDialog
            {
                PrintTicket = printTicket ?? new PrintTicket
                {
                    PageOrientation = PageOrientation.Portrait, //TODO-Print-Configuration : PageOrientation 
                    CopyCount = 1,
                    PageMediaSize = new PageMediaSize(PageMediaSizeName.ISOA4) //TODO-Print-Configuration : PageMediaSize
                }
            };
        }
        // TODO: Move ViewProxy.FastPrint Here
    }

    public static class SizeExtension
    {
        public static bool IsThinThan(this Size sizeA, Size sizeB)
        {
            return sizeA.Width / sizeA.Height < sizeB.Width / sizeB.Height;
        }
    }
}
