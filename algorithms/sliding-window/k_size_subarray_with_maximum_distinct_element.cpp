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
  for(int i=0;i<k;i++){
    mp[v[i]]++;
  }
  ll ans=(ll)mp.size();
  for(int i=k;i<n;i++){
    mp[v[i]]++;
    mp[v[i-k]]--;
    if(mp[v[i-k]]<=0) mp.erase(v[i-k]);
    ans=max(ans,(ll)mp.size());
  }
  cout<<ans<<endl;
  return 0;
}