#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

int dp[10][2][2];
// dp function
int f(string s,int idx,int tight,int flag){
  if(idx==s.size()) return flag==1;
  if(dp[idx][tight][flag]!=-1) return dp[idx][tight][flag];
  int limit=(tight)? s[idx]-'0':9;
  int ans=0;
  for(int dig=0;dig<=limit;dig++){
    int newTight=(tight && (dig==(s[idx]-'0')));
    int newFlag=(flag||dig==3);
    ans+=f(s,idx+1,newTight,newFlag);
  }
  return dp[idx][tight][flag]=ans;
}
// ---------- Write solution here ----------
void solve(){
  int n;
  cin>>n;
  string s=to_string(n);
  memset(dp,-1,sizeof(dp));
  int cnt3=f(s,0,1,0);
  cout<<n-cnt3<<endl;
}

// ---------- Main ----------
int main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}