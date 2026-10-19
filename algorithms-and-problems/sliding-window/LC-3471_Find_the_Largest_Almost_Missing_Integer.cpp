class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)
            return *max_element(begin(nums),end(nums));

        vector<int> mp(51,0);
        for(auto &ele : nums)
            mp[ele]++;
        
        if(k == 1){
            // maximum element with frequency = 1
            int maxi = -1;
            for(auto &ele : nums){
                if(mp[ele] == 1)
                    maxi = max(maxi,ele);
            }
            return maxi;
        }
        
        // only first and last element and only if frequenct is 1
        if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1){
            return max(nums[0],nums[n-1]);
        }

        if(mp[nums[0]] == 1)
            return nums[0];
        
        if(mp[nums[n-1]] == 1)
            return nums[n-1];

        return -1;
    }
};