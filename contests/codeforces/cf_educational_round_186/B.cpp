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
  ll a,b;
  cin>>a>>b;

  ll c=a;
  ll d=b;

  // start with white
  ll cntW=0;
  ll p=1;
  while(a>=p){
    a-=p;
    cntW++;
    p*=4;
  }

  ll cntB=0;
  p=2;
  while(b>=p){
    b-=p;
    cntB++;
    p*=4;
  }

  ll ans1;
  if(cntW>cntB){
    ans1=2*cntB+1;
  }else{
    ans1=2*cntW;
  }
  
  // start with black

  a=c;
  p=2;
  cntW=0;
  while(a>=p){
    a-=p;
    cntW++;
    p*=4;
  }

  p=1;
  b=d;
  cntB=0;
  while(b>=p){
    b-=p;
    cntB++;
    p*=4;
  } 

  ll ans2;
  if(cntB>cntW){
    ans2=2*cntW+1;
  }else{
    ans2=2*cntB;
  }
  cout<<(max(ans1,ans2))<<endl;

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