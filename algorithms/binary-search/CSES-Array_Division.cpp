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

bool isPrime(ll n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (ll i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}
bool check(vector<ll>&v,ll max_sum,ll k){
  int n=v.size();
  ll sum=0;
  ll cnt=0;
  for(int i=0;i<n;i++){
    sum+=v[i];
    if(sum>max_sum){
      cnt++;
      sum=v[i];
    }
  }
  // last subarray
  cnt++;
  return (cnt<=k);
}
// ---------- Write solution here ----------
void solve() {
  ll n,k;
  cin>>n>>k;
  vector<ll>v(n);
  for(auto &i:v) cin>>i;
  ll lo=*max_element(v.begin(),v.end());
  ll hi=accumulate(v.begin(),v.end(),0LL);
  ll ans=lo;
  while(lo<=hi){
    ll mid=(lo+(hi-lo)/2);
    if(check(v,mid,k)){
      ans=mid;
      hi=mid-1;
    }else lo=mid+1;
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