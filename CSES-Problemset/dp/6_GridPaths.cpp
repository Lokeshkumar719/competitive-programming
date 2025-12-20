#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(v[n-1][n-1]=='*' || v[0][0]=='*'){
        cout<<0<<endl;
        return;
    }
    vector<int>prev(n),curr(n);
    prev[0]=1;
    for(int j=1;j<n;j++){
        if(v[0][j]=='*') prev[j]=0;
        else prev[j]=prev[j-1]%mod;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*') curr[j]=0;
            else if(j==0) curr[j]=prev[j];
            else curr[j]=(prev[j]%mod+curr[j-1]%mod)%mod;
        }
        prev=curr;
    }
    cout<<prev[n-1]<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}