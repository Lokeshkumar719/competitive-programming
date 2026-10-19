// edges cases are critical in this
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int s = accumulate(begin(nums), end(nums), 0);
        int k = s - x;
        if (k == 0)
            return n;
        if (k < 0)
            return -1;
        int i = 0, j = 0;
        int sum = 0;
        int len = INT_MIN;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum > k) {
                sum -= nums[i++];
            }

            if (sum == k)
                len = max(len, j - i + 1);
            j++;
        }
        return (len == INT_MIN) ? -1 : n - len;
    }
};