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

  map<ll,ll>mp;
  ll sum=0;
  for(int i=0;i<k;i++){
    mp[v[i]]++;
    sum+=v[i];
  }
  ll ans=LLONG_MIN;
  if((ll)mp.size()==k){
    ans=sum;
  }
  
  for(int i=k;i<n;i++){
    mp[v[i]]++;
    sum+=v[i];

    mp[v[i-k]]--;
    sum-=v[i];

    if(mp[v[i-k]]<=0) mp.erase(v[i-k]);
    if((ll)mp.size()==k){
      ans=max(ans,sum);
    }
  }
  if(ans==LLONG_MIN){
    cout<<"Not Possible"<<"\n";
  }else cout<<ans<<"\n";
  return 0;
}