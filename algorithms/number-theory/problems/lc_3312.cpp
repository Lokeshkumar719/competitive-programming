class Solution {
    using ll = long long;
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        vector<ll> cnt(maxi + 1);
        for (auto& ele : nums)
            cnt[ele]++;

        // cnt frequency of each factor
        for (int i = 1; i <= maxi; i++) {
            for (int j = 2 * i; j <= maxi; j += i) {
                cnt[i] += cnt[j];
            }
        }

        // calcuate pairs with gcd of atleast i
        for (int i = maxi; i >= 1; i--) {
            cnt[i] *= (cnt[i] - 1);
            cnt[i] /= 2;
        }

        // substract when factor is 2i,3i,4i, ....
        for (int i = maxi; i >= 1; i--) {
            for (int j = 2 * i; j <= maxi; j += i) {
                cnt[i] -= cnt[j];
            }
        }

        // prefix sum
        for (int i = 1; i <= maxi; i++)
            cnt[i] += cnt[i - 1];

        // using binary search
        int q = queries.size();
        vector<int> ans;
        for (auto& i : queries) {
            int idx = upper_bound(cnt.begin(), cnt.end(), i) - cnt.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};