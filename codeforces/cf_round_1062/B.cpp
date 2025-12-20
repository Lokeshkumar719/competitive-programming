#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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