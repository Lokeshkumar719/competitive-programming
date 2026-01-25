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
  int n,q;
  cin>>n>>q;
  vector<int>a(n),b(n);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  vector<pair<int,int>>queries(q);
  for(int i=0;i<q;i++){
    cin>>queries[i].first;
    queries[i].first--;
    cin>>queries[i].second;
    queries[i].second--;
  }
  for(int i=0;i<n;i++){
    if(b[i]>a[i]){
      a[i]=b[i];
    }
  }
  int maxi=a[n-1];
  for(int i=n-2;i>=0;i--){
    if(a[i]>maxi){
      maxi=a[i];
    }
    a[i]=maxi;
  }
  // prefix sum
  for(int i=1;i<n;i++){
    a[i]+=a[i-1];
  }
  for(int i=0;i<q;i++){
    int l=queries[i].first;
    int r=queries[i].second;
    cout<<a[r]-((l-1>=0)? a[l-1]:0);
    cout<<" ";
  }
  cout<<endl;
  
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