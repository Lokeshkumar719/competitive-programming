#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int n;
    cin>>n;
    int cnt=0;
    vector<char>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i]=='1') cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='1') cout<<(i+1)<<" ";
    }
    cout<<endl;
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