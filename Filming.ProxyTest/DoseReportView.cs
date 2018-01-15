using System.ComponentModel.Composition;
using System.Windows.Controls;

namespace UIH.XA.PatientAdmin.View
{
    /// <summary>
    /// Interaction logic for DoseReportView.xaml
    /// </summary>
    [Export("DoseReportView")]
    [PartCreationPolicy(CreationPolicy.NonShared)]
    public partial class DoseReportView : UserControl
    {
        public DoseReportView()
        {
            //InitializeComponent();
        }
    }
}

