class Solution {
    using ll = long long;

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd;
        for (auto& ele : nums) {
            mx = max(mx, ele);
            prefixGcd.push_back(gcd(mx, ele));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0, j = n - 1;
        ll sum = 0;
        while (i < j)
            sum += gcd(prefixGcd[i++], prefixGcd[j--]);
        return sum;
    }
};