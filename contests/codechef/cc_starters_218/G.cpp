#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  if(n==1){
    cout<<0<<endl;
    return;
  }
  if(n<=3){
    cout<<1<<endl;
    return;
  }
  if(n==4 || n==6){
    cout<<2<<endl;
    return;
  }
  if(n&1){
    cout<<"-1"<<endl;
    return;
  }

  if((n&(n-1))==0){
    for(int i=3;i<=64;i++){
      if(n==(1<<i)){
        cout<<i<<endl;
        return;
      }
    }
  }

  if(n%4==0){
    int ans=0;
    while(n!=1){
      while((n/2)%4==0){
        n/=2;
        ans++;
      }
      n+=4;
      ans++;
    }
    cout<<ans<<endl;
  }
  cout<<"-1"<<endl;
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