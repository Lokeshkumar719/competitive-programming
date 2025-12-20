#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// Approach: sliding window approach
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0,r=0;
    int ans=0,sum=0;
    while(r<n){
        sum+=v[r];
        while(sum>x) sum-=v[l++];
        if(sum==x) ans++;
        r++;   
    }
    cout<<ans<<endl;
}
// T.C=O(N);
// S.C=O(1);
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}