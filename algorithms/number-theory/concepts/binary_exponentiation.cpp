#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

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

// ---------- Main ----------
int main() {
  fastio;

  ll a,b;
  cin>>a>>b;
  cout<<binaryExpo(a,b,1e9+7)<<endl;

  return 0;
}