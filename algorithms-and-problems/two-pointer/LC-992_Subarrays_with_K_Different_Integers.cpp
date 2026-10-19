class Solution {
public:
    int f(vector<int>& nums, int k){
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int>mp;
        int ans = 0;
        while(j<n){
            mp[nums[j]]++;
            while((int)mp.size() > k){
                mp[nums[i]]--;
                if(!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // we know how to count atmost k distinct element subarray
        return f(nums,k)-f(nums,k-1);
    }
};