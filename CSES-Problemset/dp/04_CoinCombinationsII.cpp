#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod=1e9+7;
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>prev(x+1,0),curr(x+1,0);
    for(int tar=0;tar<=x;tar++){
        if(tar%v[0]==0) prev[tar]=1;
    }
    for(int i=1;i<n;i++){
        for(int tar=0;tar<=x;tar++){
            int take=0;
            if(v[i]<=tar){
                take=curr[tar-v[i]]%mod;
            }
            int notTake=prev[tar]%mod;
            curr[tar]=(take%mod+notTake%mod)%mod;
        }
        prev=curr;
    }
    cout<<prev[x]%mod<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}