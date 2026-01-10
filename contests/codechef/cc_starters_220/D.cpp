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

// ---------- Write solution here ----------
void solve() {
  int n;
  cin>>n;
  vector<int>a(n),b(n);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  vector<int>pf(n,1e9),sf(n,-1);
  pf[0]=min(a[0],b[0]);
  sf[n-1]=max(a[n-1],b[n-1]);
  for(int i=1;i<n;i++){
    if(max(a[i],b[i])<pf[i-1]) break;
    if(min(a[i],b[i])>=pf[i-1]) pf[i]=min(a[i],b[i]);
    else  pf[i]=max(a[i],b[i]);
  }

  for(int i=n-2;i>=0;i--){
    if(min(a[i],b[i])>sf[i+1]) break;
    if(max(a[i],b[i])<=sf[i+1]) sf[i]=max(a[i],b[i]);
    else sf[i]=min(a[i],b[i]);
  }

  bool ans=false;
  ans=( sf[0]==max(a[0],b[0])) || (pf[n-1]==min(a[n-1],b[n-1]));

  for(int i=1;i<n-1;i++){
    if(min(a[i],b[i])>=pf[i-1] && max(a[i],b[i])<=sf[i+1]) ans=true;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
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