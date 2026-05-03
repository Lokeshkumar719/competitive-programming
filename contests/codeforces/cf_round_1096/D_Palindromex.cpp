#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;


#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

int findMex(int l,int r,vector<int>&v){
  int n=v.size();
  vector<bool>check(n/2+1,false);
  for(int i=l;i<=r;i++) check[v[i]]=true;
  for(int i=0;i<=(int)check.size();i++)
    if(!check[i]) return i;
}
// check palindrome from one zero
int checkOne(int idx,vector<int>&v){
  int n=v.size();
  int i=idx-1,j=idx+1;
  while(i>=0 && j<n){
    if(v[i]==v[j]){
      i--;j++;
    }else break;
  }
  int l=i+1,r=j-1;
  return findMex(l,r,v);
}
// take both zero in palindrome and try to expand
int checkTwo(int idx1,int idx2,vector<int>&v){
  int n=v.size();
  int i=idx1,j=idx2;
  while(i<=j){
    if(v[i]==v[j]){
      i++;j--;
    }else return 1;
  }
  i=idx1-1,j=idx2+1;
  while(i>=0 && j<n){
    if(v[i]==v[j]){
      i--;j++;
    }else break;
  }
  int l=i+1,r=j-1;
  return findMex(l,r,v);
}

// ---------- Write solution here ----------
void solve(){
  int n;cin>>n;
  vi v(2*n);
  int idx1=-1,idx2=-1;
  for(int i=0;i<2*n;i++){
    cin>>v[i];
    if(v[i]==0){
      if(idx1==-1) idx1=i;
      else idx2=i;
    }
  }
  // try to expand both zero individually
  int ans=1;
  ans=max(ans,checkOne(idx1,v));
  ans=max(ans,checkOne(idx2,v));
  // try to take them both
  ans=max(ans,checkTwo(idx1,idx2,v));
  cout<<ans<<endl;
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