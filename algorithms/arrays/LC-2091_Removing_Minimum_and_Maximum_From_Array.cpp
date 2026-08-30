class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[b])
                b = i;

            if (nums[i] < nums[a])
                a = i;
        }

        int first = 1 + max(a, b);
        int second = n - min(a, b);
        int third = min(a, b) + 1 + n - max(a, b);

        return min({first, second, third});
    }
};