#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"
const int n=5;
int dp[n];
int f(int idx,int num){
  if(idx==n){
    return 1;
  }
  if(dp[idx]!=-1) return dp[idx];
  int sum=0;
  for(int i=0;i<=9;i++){
    sum+=f(idx+1,num*10+i);
  }
  return dp[idx]=sum;
}
int main(){
  fastio;
  memset(dp,-1,sizeof(dp));
  dp[0]=f(0,0);
  cout<<dp[0]<<endl;
  return 0;
}