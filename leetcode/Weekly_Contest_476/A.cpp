class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums.back()+nums[nums.size()-2]-nums[0];
    }
};