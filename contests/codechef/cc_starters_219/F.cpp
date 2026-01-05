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
  string s;
  cin>>s;
  // Claim:In the most optimal solution we will never have a bad prefic before a good prefix
  // so if answer is K then the first K prefixies will be good
  // maximum number of good prefixes that we can obtian is min(2*(number of ones),length of string)
  vector<int>posOne;
  for(int i=0;i<n;i++){
    if(s[i]=='1') posOne.push_back(i);
  }
  ll ans=0;
  ll maxi=(ll)min(2*(int)posOne.size(),n);
  for(int i=0;i<posOne.size();i++){
    if(posOne[i]>=2*i){
      ans+=((ll)posOne[i]-(ll)2*(ll)i);
    }
  }
  cout<<maxi<<" "<<ans<<endl;
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