#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int a,b;
    cin>>a>>b;
    int numBits = (int)floor(log2(a)) + 1;
    if(b>=(1<<numBits)){
        cout<<-1<<endl;
        return;
    }
    vector<int>ans;
    for(int i=0;i<numBits;i++){
        int x=(a&(1<<i));
        int y=(b&(1<<i));

        if(x!=0 && y==0 || (x==0 && y!=0)){
            ans.push_back(1<<i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &el:ans){
        cout<<el<<" ";
    }
    if(ans.size())cout<<endl;
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