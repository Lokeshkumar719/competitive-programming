#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    cout<<dp[n]%mod<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}