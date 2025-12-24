#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
bool check(int k,vector<int>&v,int h){
  vector<int>temp(k);
  for(int i=0;i<k;i++){
    temp.push_back(v[i]);
  }

  sort(temp.begin(),temp.end(),[](int a,int b){
    return a>b;
  });

  int minHeightRequired=0;
  for(int i=0;i<k;i+=2){
    minHeightRequired+=temp[i];
  }

  return minHeightRequired<=h;

}
void solve() {
  int n,h;
  cin>>n>>h;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  int lo=0;
  int hi=n;
  int ans=lo;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(check(mid,v,h)){
      ans=mid;
      lo=mid+1;
    }else{
      hi=mid-1;
    }
  }
  cout<<ans<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}