class Solution {
using ll=long long;
public:
    long long minOperations(vector<int>& v) {
        int n=v.size();
        ll ans=0LL;
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1]){
                ans+=(v[i-1]-v[i]);
            }
        }
        return ans;
    }
};