#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// as first factor(except 1) is always prime for n>1
// T.C=O(root n+logn)
vector<int> primeFactorization(int n){
  vector<int> primeFactors;
  for(int d=2;d*d<=n;d++){
    if(n%d==0){
      while(n%d==0){
        primeFactors.push_back(d);
        n/=d;
      }
    }
  }
  if(n>1)
    primeFactors.push_back(n);
  return primeFactors;
}

int32_t main() {
  fastio;
  int n;
  cin >> n;
  vector<int> ans=primeFactorization(n);
  for(int &fact:ans) cout<<fact<<" ";
  return 0;
}