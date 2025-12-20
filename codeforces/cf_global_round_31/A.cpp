#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int l,a,b;
    cin>>l>>a>>b;
    int ans=a;
    for(int i=1;i<l;i++){
        ans=max(ans,(a+i*b)%l);
    }
    cout<<ans<<endl;
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