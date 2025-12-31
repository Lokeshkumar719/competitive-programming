#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const int N=(int)1e5+1;

vector<int> sieve(){
  vector<int>spf(N);
  for(int i=1;i<N;i++) spf[i]=i;
  for(int i=2;i<N;i++){
    if(spf[i]==i){
      for(int j=i;j<N;j+=i){
        if(spf[j]==j){
          spf[j]=i;
        }
      }
    }  
  }
  return spf;
}

vector<int>findPrimes(int n,vector<int>&spf){
  vector<int>ans;
  while(n>1){
    int x=spf[n];
    ans.push_back(x);
    while(n%x==0){
      n/=x;
    }
  }
  return ans;
}
// ---------- Main ----------
int main() {
  fastio;
  vector<int>spf=sieve();
  int n,m;
  cin>>n>>m;
  vector<int>isActive(n+1,0);
  vector<int>occupied(n+1,0);
  while(m--){
    char type;
    int num;
    cin>>type;
    cin>>num;
    vector<int>primeFactors=findPrimes(num,spf);
    if(type=='+'){
      if(occupied[num]){
        cout<<"Already on"<<endl;
      }else{
        int conflict=0;
        for(auto &i:primeFactors){
          if(isActive[i]!=0){
            conflict=isActive[i];
            break;
          }
        }
        if(conflict){
          cout<<"Conflict with "<<conflict<<endl;
        }else{
          for(auto &i:primeFactors){
            isActive[i]=num;
          }
          occupied[num]=1;
          cout<<"Success "<<endl;
        }
      }
    }else{
      if(!occupied[num]){
        cout<<"Already off "<<endl;
      }else{
        for(auto &i:primeFactors){
          isActive[i]=0;
        }
        occupied[num]=0;
        cout<<"Success "<<endl;
      }
    }
  }
  return 0;
}