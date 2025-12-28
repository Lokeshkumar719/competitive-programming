#include <bits/stdc++.h>
using namespace std;

using ll = long long;


#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

ll binaryExpo(ll a,ll b,ll mod){
  ll ans=1;
  a%=mod;
  while(b){
    if(b&1){
      ans=(ans*a)%mod;
    }
    b>>=1;
    a=(a*a)%mod;
  }
  return ans;
}

// ---------- Write solution here ----------
void solve() {
  ll a,b,c;
  cin>>a>>b>>c;
  ll x=binaryExpo(b,c,1e9+6);
  ll ans=binaryExpo(a,x,1e9+7);
  cout<<ans<<endl;
}

// ---------- Main ----------
int main() {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}