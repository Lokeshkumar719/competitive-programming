#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod=998244353;
void solve() {
  int n,m;
  cin>>n>>m;
  if(n==1){
    cout<<(m+1)<<endl;
    return;
  }
  int bits=(int)log2(m)+1;
  int ans=(1<<(bits-1))*2;
  ans+=2;
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