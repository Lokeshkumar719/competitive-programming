class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int n=nums.size();
      int ans=0;
      for(int bits=0;bits<=31;bits++){
        // find LIS in elements with bits as set bit
        vector<int>bs;
        for(auto &ele:nums){
          if(ele&(1<<bits)){
            if(bs.size()==0 || ele>bs.back()){
              bs.push_back(ele);
            }else{
              int idx=lower_bound(bs.begin(),bs.end(),ele)-bs.begin();
              bs[idx]=ele;
            }
          }
        }
        ans=max(ans,(int)bs.size());
      }
      return ans;
    }
};