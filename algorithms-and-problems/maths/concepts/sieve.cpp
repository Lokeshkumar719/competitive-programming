#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// T.C=O(nlog(logn)) and S.C=O(n)
vector<bool> sieve(ll n){
  vector<bool>isPrime(n+1,true);
  isPrime[0]=isPrime[1]=false;
  for(ll i=2;i*i<=n;i++){
    if(isPrime[i]){
      for(ll j=i*i;j<=n;j+=i){
        isPrime[j]=false;
      }
    }
  }
  return isPrime;
}

int main() {
  fastio;

  ll n;
  cin>>n;
  vector<bool> ans=sieve(n);
  for(int i=2;i<=n;i++){
    if(ans[i]){
      cout<<i<<" ";
    }
  }
  return 0;
}