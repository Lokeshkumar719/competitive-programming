#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    int a=(x&y);
    int b=(y&z);
    int c=(z&x);
    int d=(x&y&z);

    if(a==b and b==c and c==d ){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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