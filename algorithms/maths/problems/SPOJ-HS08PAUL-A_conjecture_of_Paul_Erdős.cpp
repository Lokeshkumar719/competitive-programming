#include <bits/stdc++.h>
using namespace std;
int N=(int)1e7;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

vector<bool> sieve(){
  vector<bool>ans(N,true);
  ans[0]=ans[1]=false;
  for(int i=2;i*i<N;i++){
    if(ans[i]){
      for(int j=i*i;j<N;j+=i){
        ans[j]=false;
      }
    }
  }
  return ans;
}
vector<bool> checkType(vector<bool>&isPrime){
  vector<bool>ans(N,false);
  for(int i=1;i*i<N;i++){
    for(int j=1;((i*i)+(j*j*j*j))<N;j++){
      int num=(i*i)+(j*j*j*j);
      if(isPrime[num]){
        ans[num]=1;
      }
    }
  }
  return ans;
}

// ---------- Main ----------
int main() {
  fastio;

  
  vector<bool>isPrime=sieve();
  vector<bool>isType=checkType(isPrime);
  // calculate prefix sum
  vector<int>pre(N,0);
  for(int i=0;i<N;i++){
    pre[i]=(isPrime[i] && isType[i]);
  }
  // take prefix sum
  for(int i=1;i<N;i++){
    pre[i]+=pre[i-1];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin>>n;
    cout<<pre[n]<<endl;
  }

  return 0;
}