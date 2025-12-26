#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  string ans=v[0];
  for(int i=1;i<n;i++){
    string x=ans+v[i];
    string y=v[i]+ans;
    if(x<y){
      ans=ans+v[i];
    }else{
      ans=v[i]+ans;
    }
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
