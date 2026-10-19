class Solution {
public:
    void reverse(vector<int> &nums, int i, int j){
        while(i<j)
            swap(nums[i++],nums[j--]);
    }
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = n-1;
        ans[0] = nums[0];ans[n-1] = nums[1];
        for(int k = 2; k<n; k++){
            int ele = nums[k];
            if(ans[i] > ans[j])
                ans[++i] = ele;
            else
                ans[--j] = ele;
        }
        reverse(ans,j,n-1);
        return ans;
    }
};