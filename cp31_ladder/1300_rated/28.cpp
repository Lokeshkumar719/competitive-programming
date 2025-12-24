#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  int sum=0;
  vector<int>v(n);
  map<int,int>mp;
  for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];
    mp[v[i]]++;
  }
  vector<int>ans;
  for(int i=0;i<n;i++){
    int rem=sum-v[i];
    if(rem%2==0){
      mp[v[i]]--;
      if(mp.count(rem/2) && mp[rem/2]>0){
        ans.push_back(i+1);
      }
      mp[v[i]]++;
    }
  }
  cout<<ans.size()<<endl;
  for(auto &ele:ans){
    cout<<ele<<" ";
  }
  cout<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}