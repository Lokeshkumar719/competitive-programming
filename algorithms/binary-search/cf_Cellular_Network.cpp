#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- Utility functions ----------
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll binpow(ll a, ll b, ll mod = MOD) {
  ll res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

// ---------- Write solution here ----------
void solve() {
  ll n,m;
  cin>>n>>m;
  vector<ll>cities(n),tower(m);
  for(auto &i:cities){
    cin>>i;
  }
  for(auto &i:tower){
    cin>>i;
  }
  ll ans=0LL;
  for(int i=0;i<n;i++){
    ll dist=LLONG_MAX;
    auto it=lower_bound(tower.begin(),tower.end(),cities[i]);
    if(it!=tower.end()){
      dist=min(dist,abs(*it-cities[i]));
      it--;
      if(it!=(tower.begin()-1)){
        dist=min(dist,abs(*it-cities[i]));
      }
    }else{
      dist=min(dist,abs(tower[m-1]-cities[i]));
    }
    ans=max(ans,dist);
  }
  cout<<ans<<endl;
}

// ---------- Main ----------
int main() {
  fastio;

  int t=1;
  while (t--) {
    solve();
  }

  return 0;
}