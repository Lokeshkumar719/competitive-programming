#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"
int dp[11][10];
// ---------- Write solution here ----------
int solve(int n,vector<int>& digits,int idx,int prev){
  if(idx==n) return 1;
  if(dp[idx][prev]!=-1) return dp[idx][prev];
  int ans=0;
  for(int i=0;i<digits.size();i++){
    int dig=digits[i];
    if(prev==0 || abs(dig-prev)<=2){
      ans+=solve(n,digits,idx+1,dig);
    }
  }
  return dp[idx][prev]=ans;
}
// ---------- Main ----------
int main(){
  fastio;
  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    int m,n;
    cin>>m>>n;
    vector<int>digits(m);
    for(auto &i:digits) cin>>i;
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<i<<": "<<solve(n,digits,0,0)<<endl;
  }
    return 0;
  }
  
