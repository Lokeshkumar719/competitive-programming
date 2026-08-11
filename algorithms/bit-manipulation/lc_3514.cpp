class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int left_bit = log2(maxi) + 1;
        int size = (1 << left_bit);
        vector<bool> uniq_pair_zor(size, false);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                uniq_pair_zor[nums[i] ^ nums[j]] = true;
            }
        }
        vector<bool> uniq_trip_zor(size, false);
        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (!uniq_pair_zor[i])
                continue;
            for (auto& ele : nums) {
                uniq_trip_zor[ele ^ i] = true;
            }
        }
        for (auto ele : uniq_trip_zor)
            ans += (ele == true);
        return ans;
    }
};