class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;

public:
    ll binExpo(ll a, ll b, ll MOD) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    ll getSum(ll l, ll r, ll n) {
        // return sum of n terms with first term as l and last as l
        ll sum = (l + r) % MOD;
        sum = (sum * n) % MOD;
        // now divide by 2 so need inverse modulo
        sum = (sum * binExpo(2LL, MOD - 2, MOD)) % MOD;
        return sum;
    }
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll res = k;
        ll cost = 1;
        ll ans = 0;
        for (auto& ele : nums) {
            if (ele > res) {
                ll need = ele - res;
                // ceil of need/k
                ll num_of_terms_of_AP = (need + k - 1) / k;
                // as cost increase by one only so first term=cost only
                ll first_term = cost;
                ll last_term = cost + num_of_terms_of_AP - 1;
                // get the sum
                ll sum = getSum(first_term, last_term, num_of_terms_of_AP);
                // new Resources
                res += k * num_of_terms_of_AP;
                // new Cost
                cost += num_of_terms_of_AP;
                ans = (ans + sum) % MOD;
            }
            res -= ele;
        }
        return ans;
    }
};