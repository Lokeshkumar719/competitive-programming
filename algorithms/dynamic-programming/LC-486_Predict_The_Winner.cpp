class Solution {
public:
    int dp[22][22];
    int f(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return nums[i];
        int first = nums[i] + min(f(i + 2, j, nums), f(i + 1, j - 1, nums));
        int second = nums[j] + min(f(i + 1, j - 1, nums), f(i, j - 2, nums));
        return dp[i][j] = max(first, second);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int score1 = f(0, n - 1, nums);
        int total = accumulate(nums.begin(), nums.end(), 0);
        return 2 * score1 >= total;
    }
};