#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> pp;
void solve() {
  int n;
  cin>>n;
  vector<int>a(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  priority_queue<pp,vector<pp>,greater<pp>>pq;
  for(int i=0;i<n;i++){
    pq.push({c[i],i});
  }
  int cnt=0;
  set<int>s;
  int ans=0;
  while(cnt!=n){
    int cost=pq.top().first;
    int idx=pq.top().second;
    pq.pop();
    for(int i=idx;i<n;i++){
      if(!s.count(i)){
        ans+=((cost)*(a[i]));
        s.insert(i);
        cnt++;
      } 
    }
  }
  cout<<ans<<endl;
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