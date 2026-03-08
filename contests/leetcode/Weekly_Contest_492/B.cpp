class Solution {
using ll=long long;
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        ll sum  = accumulate(nums.begin(),nums.end(),0LL) - nums[n-1];
        ll prod = 1LL;
        if(sum == prod) return n-1;
        for(int i = n-2;i>=0;i--){
            prod *= nums[i+1];
            sum -= nums[i];
            if(sum == prod) return i;
            else if(sum < prod) break;
        }
        return -1;
    }
};