class Solution {
using ll=long long;
public:
  int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
    vector<ll>ans(n,LLONG_MAX);
    ans[0]=0;
    for(auto &it:restrictions){
      int idx=it[0];
      int maxi=it[1];
      ans[idx]=maxi;
    }
    for(int i=1;i<n;i++){
      ans[i]=min(ans[i],ans[i-1]+diff[i-1]);
    }
    for(int i=n-1;i>0;i--){
      ans[i-1]=min(ans[i-1],ans[i]+diff[i-1]);
    }
    return (int)*max_element(ans.begin(),ans.end());
  }
};