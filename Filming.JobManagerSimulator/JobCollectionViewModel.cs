using System.Collections.ObjectModel;
using UIH.XA.Common.MVVM;

namespace UIH.XA.Filming.JobManagerSimulator
{
    class JobCollectionViewModel : NotificationObject
    {
        public JobCollectionViewModel()
        {
            JobCollection = new ObservableCollection<JobViewModel>();
        }

        public ObservableCollection<JobViewModel> JobCollection { get; set; }
    }
}
