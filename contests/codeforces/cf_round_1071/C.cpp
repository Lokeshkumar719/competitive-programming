#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  int ans=max(v[0],v[1]-v[0]);
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