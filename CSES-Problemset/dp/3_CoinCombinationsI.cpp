// Combination sum4 on leetcode
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
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=v[j]){
                dp[i]=(dp[i]+dp[i-v[j]])%mod;
            }
        }
    }
    cout<<(dp[x])<<endl;
}

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}