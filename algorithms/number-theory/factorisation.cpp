#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> findFactors(ll n){
  vector<ll>factors;
  for(ll d=1;d*d<=n;d++){
    if(n%d==0){
      factors.push_back(d);
      if(n/d!=d){
        factors.push_back(n/d);
      }
    }
  }
  return factors;
}
int main() {
  ll n;
  cin>>n;
  vector<ll> ans=findFactors(n);
  sort(ans.begin(),ans.end());
  for(ll &fact:ans) cout<<fact<<" ";
  return 0;
}