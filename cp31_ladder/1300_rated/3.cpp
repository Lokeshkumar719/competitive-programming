#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  int sum=0;
  set<int>s;
  s.insert(0);
  for(int i=0;i<n;i++){
    if((i+1)&1){
      sum+=v[i];
    }else sum-=v[i];
    if(s.count(sum)){
      cout<<"YES"<<endl;
      return;
    }
    s.insert(sum);
  }
  cout<<"NO"<<endl;
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