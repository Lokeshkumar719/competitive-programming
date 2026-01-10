#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod=1e9+7;
void solve() {
    int n,x;
    cin>>n>>x;

    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<int>prev(x+1,0);
    for (int price = prices[0]; price <= x; price++) {
        prev[price] = pages[0];
    }

    for(int i=1;i<n;i++){
        for(int price=x;price>=0;price--){
            int pick=0;
            if(price>=prices[i]) pick=(pages[i]%mod+prev[price-prices[i]]%mod)%mod;
            int notPick=prev[price]%mod;
            prev[price]=max(pick,notPick);
        }
    }
    cout<<prev[x]%mod;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}