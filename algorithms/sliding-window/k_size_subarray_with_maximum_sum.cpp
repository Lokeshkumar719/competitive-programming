#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Main ----------
int main() {
  fastio;
  int n,k;
  cin>>n>>k;
  vector<ll>v(n);
  for(auto &i:v) cin>>i;
  ll ans=LLONG_MIN;
  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=v[i];
    if(i>=k){
      sum-=v[i-k];
    }
    if(i>=k-1){
      ans=max(ans,sum);
    }
  }
  cout<<ans<<endl;
  return 0;
}