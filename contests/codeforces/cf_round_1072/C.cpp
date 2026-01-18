#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ll f(ll n,ll k,map<ll,ll>&mp){
  if(n==k) return (ll)0;
  if(n<k) return (ll)1e9;
  if(mp.count(n)) return mp[n];
  ll first_half=n/2;
  ll second_half=n-first_half;
  return mp[n]=(1+min(f(first_half,k,mp),f(second_half,k,mp)));
}

// ---------- Write solution here ----------
void solve() {
  ll n,k;
  cin>>n>>k;
  map<ll,ll>mp;
  mp[n]=f(n,k,mp);
  ll ans=mp[n];
  if(ans>=1e9){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
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