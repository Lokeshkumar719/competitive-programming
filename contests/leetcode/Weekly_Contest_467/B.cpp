class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>s;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(s.count(nums[i])==0){
                ans.push_back(nums[i]);
                s.insert(nums[i]);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};