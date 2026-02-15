class Solution {
using ll=long long;
public:
  vector<ll>dp;
  ll f(int indx,vector<int>&nums,vector<int>& colors){
    if(indx==0) return (ll)nums[0];
    if(indx<0) return 0;
    if(dp[indx]!=-1) return dp[indx];
    ll pick=0;
    ll notPick=0;
    if(colors[indx]==colors[indx-1]){
        pick+=(nums[indx]+f(indx-2,nums,colors));
        notPick+=(f(indx-1,nums,colors));
    }else{
        pick+=(nums[indx]+f(indx-1,nums,colors));
    }
    return dp[indx]=max(pick,notPick);
  }
  long long rob(vector<int>& nums, vector<int>& colors) {
    int n=nums.size();
    dp.clear(); 
    dp.resize(n+1,-1);
    return f(n-1,nums,colors);
  }
};