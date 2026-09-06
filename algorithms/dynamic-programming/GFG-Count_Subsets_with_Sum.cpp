class Solution {
	public:
	int perfectSum(vector<int>& nums, int target) {
		int n = nums.size();
		int sum = accumulate(begin(nums), end(nums), 0);
		if(sum<target)
		    return 0;
		    
		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
		// correct base case as 0 is also present
		if(nums[0] == 0){
		    dp[0][0] = 2;
		}else{
		    dp[0][0] = 1;
		    if(nums[0]<=target) dp[0][nums[0]] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int tar = 0; tar <= target; tar++) {
			    int ans = dp[i - 1][tar];
				if ((tar - nums[i]) >= 0)
					ans += dp[i - 1][tar - nums[i]];
				
				dp[i][tar] = ans;
			}
		}
		return dp[n - 1][target];
	}
};
