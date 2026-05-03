class Solution {
using ll=long long;
public:
    int compareBitonicSums(vector<int>& v) {
        int n=v.size();
        int idx=max_element(v.begin(),v.end())-v.begin();
        ll asc=0LL,desc=0LL;
        for(int i=0;i<n;i++){
            if(i<=idx){
                asc+=v[i];
            }
            if(i>=idx){
                desc+=v[i];
            }
        }
        if(asc>desc) return 0;
        if(asc<desc) return 1;
        return -1;
    }
};