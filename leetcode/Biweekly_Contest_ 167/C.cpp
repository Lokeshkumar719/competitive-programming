class ExamTracker {
public:
    vector<int>time;
    vector<long long>pre;
    ExamTracker() {
        
    }
    
    void record(int t, int score) {
        time.push_back(t);
        pre.push_back(score);
        if(pre.size()>1){
            pre[pre.size()-1]+=pre[pre.size()-2];
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        int i1=(lower_bound(time.begin(),time.end(),startTime)-time.begin());
        int i2=(lower_bound(time.begin(),time.end(),endTime)-time.begin());
        if(time[i1]>endTime) return 0; 
        i1-=1;
        if(time[i2]!=endTime){
            i2-=1;
        }
        if(i2>=0 && i1>=0) return pre[i2]-pre[i1];
        if(i1<0 && i2>=0) return pre[i2]; 
        return pre[i2];
    }
    
};
