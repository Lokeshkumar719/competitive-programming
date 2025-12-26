#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  if(n<=4 || n==6){
    cout<<"Yes"<<endl;
    return;
  }
  if(n&1){
    cout<<"No"<<endl;
    return;
  }
  if(((n)&(n-1))==0 || n%4==0){
    cout<<"Yes"<<endl;
    return;
  }
  cout<<"No"<<endl;
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