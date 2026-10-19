class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        int i = 0;
        while(i<n){
            int r = ((nums[i]%k) + k)%k;
            int j = i;
            while(j<n && ((nums[j]%k)+k)%k % k == r){
                j++;
            }
            int len = j-i;
            if(!r){
                ans = max(ans,len);
            }else{
                int period = k/gcd(k,r);
                int curr = len - ((len-1)%period);
                ans = max(ans,curr);
            }
            i = j;
        }
       
        return ans;
    }
};