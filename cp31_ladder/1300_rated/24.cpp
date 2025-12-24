#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];
  }
  // kadane's for 0 to n-2 and then from 1 to n-1
  int ans=v[0];
  int maxi=v[0];
  for(int i=1;i<n-1;i++){
    maxi=max(v[i],maxi+v[i]);
    ans=max(ans,maxi);
  }
  maxi=v[1];
  ans=max(ans,maxi);
  for(int i=2;i<n;i++){
    maxi=max(v[i],maxi+v[i]);
    ans=max(ans,maxi);
  }
  if(sum>ans){
    cout<<"YES"<<endl;
  }else cout<<"NO"<<endl;
}
int32_t main() {
  fastio;
  int t;
  cin >> t;
  while(t--) {
      solve();
  }
  return 0;
}