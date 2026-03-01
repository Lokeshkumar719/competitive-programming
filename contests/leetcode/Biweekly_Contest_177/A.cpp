class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j] && mp[nums[i]]!=mp[nums[j]]){
                    return {nums[i],nums[j]};
                }
            }
        }
        return {-1,-1};
    }
};