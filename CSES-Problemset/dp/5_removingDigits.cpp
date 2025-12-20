#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
vector<int> getDigit(int n){
    vector<int>digits;
    while(n){
        if(n%10!=0){
            digits.push_back(n%10);
        }
        n/=10;
    }
    return digits;
}
void solve() {
    int n;
    cin>>n;

    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        vector<int>digits=getDigit(i);
        for(int j=0;j<digits.size();j++){
            if(i>=digits[j]){
                dp[i]=min(dp[i],1+dp[i-digits[j]]);
            }  
        }
    }
    cout<<dp[n]<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}