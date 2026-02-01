class Solution {
using ll=long long;
public:
  int minimumK(vector<int>& nums) {
    int n=nums.size();
    ll lo=(ll)1;
    ll hi=(ll)1e9;
    ll ans=hi;
    while(lo<=hi){
      ll mid=lo+(hi-lo)/2;
      ll cnt=0;
      for(auto &ele:nums){
        cnt+=(ele+mid-1)/mid;
      }
      if(cnt<=mid*mid){
        ans=mid;
        hi=mid-1;
      }else lo=mid+1;
    }
    return (int)ans;
  }
};