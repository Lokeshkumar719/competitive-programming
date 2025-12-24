#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  vector<int>factors;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      n/=i;
      factors.push_back(i);
      if(factors.size()==2){
        break;
      }
    }
  }
  if(factors.size()!=2 || factors[0] == factors[1] || factors[0]==n || factors[1]==n){
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl;
  cout<<factors[0]<<" "<<factors[1]<<" "<<n<<endl;
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