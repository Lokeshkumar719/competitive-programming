#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// finding the prime decompostion using spf vector 
vector<pll> spf_primeFactors(int x,vector<ll> &spf){
  vector<pll> ans;
  while(x!=1){
    ll prime=spf[x];
    ll cnt=0;
    while(x%prime==0){
      cnt++;
      x/=prime;
    }
    ans.push_back({prime,cnt});
  }
  return ans;
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

int main() {
  fastio;

  int n;
  cin >> n;
  vector<ll> spfVector=spf_sieve(n);
  vector<pll> factorisation=spf_primeFactors(n,spfVector);
  for(auto &it:factorisation){
    cout<<it.first<<":"<<it.second<<endl;
  }
  
  return 0;
}