class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i=0;
        int zeros = 0;
        for(int j=0;j<n;j++){
            zeros += (nums[j] == 0);
            while(zeros > k)
                zeros -= (nums[i++] == 0);

            ans = max(ans,j-i+1);
        }
        return ans;
    }
};