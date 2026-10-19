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
int fact[11];

bool checkParity(int missed,int diff){
  if((missed&1) && (missed&1)) return true;
  if((missed%2==0) && (missed%2==0)) return true;
  return false;
}

void solve(){
  string s1,s2;
  cin>>s1>>s2;

  int reqSum=0;
  for(int i=0;i<s1.size();i++){
    reqSum=reqSum+((s1[i]=='+')? 1:-1);
  }

  int missed=0;
  int sum=0;
  for(int i=0;i<s2.size();i++){
    missed+=(s2[i]=='?');
    if(s2[i]=='+') sum++;
    else if(s2[i]=='-') sum--;
  }

  int diff=abs(sum-reqSum);
  if(diff>missed || !checkParity(missed,diff)){
    double ans=0;
    printf("%.10f",ans);
    return;
  }

  fact[0]=1;
  for(int i=1;i<11;i++){
    fact[i]=i*fact[i-1];
  }

  int type1=(missed-diff)/2;
  int type2=missed-type1;
 
  int totalCase=(1<<missed);
  int favour=fact[missed]/(fact[type1]*fact[type2]);
  double ans=0;
  ans=(double)favour/totalCase;
  printf("%.9f",ans);
}

// ---------- Main ----------
int main() {
  fastio;
  solve();
  return 0;
}