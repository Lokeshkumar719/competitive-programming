class Solution {
using ll=long long;
static const ll mod=1e9+7;
public:
    int maxValue(vector<int>& v1, vector<int>& v0) {
        int n=v1.size();
        int maxi=3e5;
        vector<ll>pow2(maxi,0);
        pow2[0]=1;
        for(int i=1;i<maxi;i++) pow2[i]=(pow2[i-1]*2)%mod;

        vector<int>v;
        for(int i=0;i<n;i++) v.push_back(i);

        sort(v.begin(),v.end(),[&](int a,int b){
            // id v0[0]==0 a should come last in v
            if(!v0[a]) return false;
            // if v0[b]==0 b should come to last(means a should come first)
            if(!v0[b]) return true;
            if(v1[a]==v1[b]) return v0[a]>v0[b];
            return v1[a]<v1[b];
        });

        ll ans=0LL;
        int pw=0;
        for(auto &i:v){
            pw+=v0[i];
            while(v1[i]--){
                ans=(ans+pow2[pw])%mod;
                pw++;
            }
        }
        return ans;  
    }
};