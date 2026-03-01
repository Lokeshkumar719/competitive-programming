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
vector<ll> find_max_3(vector<ll>& v){
  ll n=(ll)v.size();
  vector<pll>temp(n);
  for(int i=0;i<n;i++){
    temp[i].first=v[i];
    temp[i].second=i;
  }
  sort(temp.begin(),temp.end());
  vector<ll>maxi(3);
  for(int i=n-1;i>=n-3;i--){
    maxi[n-i-1]=temp[i].second;
  }
  return maxi;
}
// ---------- Write solution here ----------
void solve() {
  ll n;
  cin>>n;
  vector<ll>a(n);
  vector<ll>b(n);
  vector<ll>c(n);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  for(auto &i:c) cin>>i;
  vector<ll>max_a=find_max_3(a);
  vector<ll>max_b=find_max_3(b);
  vector<ll>max_c=find_max_3(c);
  ll sum=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        ll x=max_a[i];ll y=max_b[j];ll z=max_c[k];
        if((x==y) || (y==z) || (z==x))
          continue;
          // cout<<a[x]+b[y]+c[z]<<" ";
        sum=max(sum,a[x]+b[y]+c[z]);
      }
    }
  }
  cout<<sum<<endl;
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