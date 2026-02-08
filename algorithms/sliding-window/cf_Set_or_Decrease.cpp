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
bool check(vector<ll>&v,ll sum,ll operations,ll k){
  ll n=(ll)v.size();
  if(sum-operations<=k) return true;
  for(ll i=n-1;i>=max(1LL,n-operations);i--){
    sum-=v[i];
    ll operations_left=(operations-(n-i));
    ll tempSum=(sum-operations_left)+(n-i)*(v[0]-operations_left);
    if(tempSum<=k) return true;
  }
  return false;
}
// ---------- Write solution here ----------
void solve() {
  ll n,k;
  cin>>n>>k;
  vector<ll>v(n); 
  for(auto &i:v) cin>>i;
  sort(v.begin(),v.end());
  ll sum=accumulate(v.begin(),v.end(),0LL);
  ll lo=0,hi=1e10,ans=hi;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(check(v,sum,mid,k)){
      ans=mid;
      hi=mid-1;
    }else lo=mid+1;
  }
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