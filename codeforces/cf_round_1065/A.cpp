#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int n;
    cin>>n;
    int ans=0;
    if(n&1) cout<<0<<endl;
    else{
        cout<<n/4+1;
    }
}
int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}