using UIH.XA.Common.MVVM;
using UIH.XA.Core;

namespace UIH.XA.Filming.JobManagerSimulator
{
    class JobViewModel : NotificationObject
    {
        #region [--ID--]

        private string _id;

        public string ID
        {
            get { return _id; }
            set
            {
                this.LogDevInfo(string.Format("ID Changes From [{0}] to [{1}]", _id, value));
                if (_id == value) return;
                _id = value;
                RaisePropertyChanged(() => ID);
            }
        }

        #endregion [--ID--]


        #region [--Status--]

        private string _status;

        public string Status
        {
            get { return _status; }
            set
            {
                this.LogDevInfo(string.Format("Status Changes From [{0}] to [{1}]", _status, value));
                if (_status == value) return;
                _status = value;
                RaisePropertyChanged(() => Status);
            }
        }

        #endregion [--Status--]


        #region [--Progress--]

        private string _progress;

        public string Progress
        {
            get { return _progress; }
            set
            {
                this.LogDevInfo(string.Format("Progress Changes From [{0}] to [{1}]", _progress, value));
                if (_progress == value) return;
                _progress = value;
                RaisePropertyChanged(() => Progress);
            }
        }

        #endregion [--Progress--]

    }
}
