#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

ll dp[20][2][2];
// ---------- Write solution here ----------
ll solve(int idx,string &s,int tight,int leading,int prev){
  if(idx==s.size()) return 1;
  if(dp[idx][tight][leading]!=-1) return dp[idx][tight][leading];
  int limit=(tight? s[idx]-'0':9);
  ll ans=0;
  for(int dig=0;dig<=limit;dig++){
    if(dig==prev && !leading ) continue;
    ans+=(solve(idx+1,s,tight&(dig==(s[idx]-'0')),leading&(!dig),dig));
  }
  return dp[idx][tight][leading]=ans;
}
// ---------- Main ----------
int main(){
  fastio;
  ll a,b;
  cin>>a>>b;

  string ub=to_string(b);
  string lb=to_string(a-1);

  memset(dp,-1,sizeof(dp));
  ll rightAns=solve(0,ub,1,1,10);
  memset(dp,-1,sizeof(dp));
  ll leftAns=solve(0,lb,1,1,10);

  cout<<(rightAns-leftAns);

  return 0;
}