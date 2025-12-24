#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n,x,y;
  cin>>n>>x>>y;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int ans=0;
  map<int,int>mp;
  for(int i=n-1;i>=0;i--){
    int val1=(v[i]+y)%y;
    int val2=(v[i]%x);
    if(mp.count(val1) && mp.count(val2)){
      ans++;
    }
    mp[val1]++;
    mp[val2]++;
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