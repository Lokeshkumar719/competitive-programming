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

// finding the prime decompostion using spf vector 
void spf_primeFactors(int x,vector<ll> &spf,map<int,vector<int>>&mp){
  while(x!=1){
    ll prime=spf[x];
    ll cnt=0;
    while(x%prime==0){
      cnt++;
      x/=prime;
    }
    mp[prime].push_back(cnt);
  }
}

// creating the spf sieve(smallest prime sieve)
vector<ll> spf_sieve(ll n){
  vector<bool>isPrime(n+1,true);
  isPrime[0]=isPrime[1]=false;
  vector<ll>spf(n+1,1e9);
  for(ll i=2;i<=n;i++){
    if(isPrime[i]){
      spf[i]=i;
      for(ll j=i*i;j<=n;j+=i){
        isPrime[j]=false;
        spf[j]=min(spf[j],i);
      }
    }
  }
  return spf;
}

// ---------- Main ----------
int main() {
  fastio;
  vector<ll>prime=spf_sieve(2e5);
  int n;
  cin>>n;
  vector<int>v(n);
  for(auto &i:v) cin>>i;
  map<int,vector<int>>mp;
  for(int &ele:v){
    spf_primeFactors(ele,prime,mp);
  }
  ll ans=1;
  for(auto &it:mp){
    int x=it.second.size();
    if(x<n-1){
      continue;
    }else if(x==n-1){
      sort(it.second.begin(),it.second.end());
      ans=(ans*binpow(it.first,it.second[0]));
    }else{
      sort(it.second.begin(),it.second.end());
      ans=(ans*binpow(it.first,it.second[1]));
    }
  }
  cout<<ans<<endl;
  return 0;
}