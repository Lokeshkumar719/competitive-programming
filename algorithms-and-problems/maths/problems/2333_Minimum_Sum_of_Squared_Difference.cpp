class Solution {
public:
    using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        ll maxDiff = 0;
        for(int i=0;i<n;i++){
            maxDiff = max(maxDiff,(ll)abs(nums1[i] - nums2[i]));
        }
        vector<int> countDiff(maxDiff+1,0);
        for(int i=0;i<n;i++){
            int diff = abs(nums1[i] - nums2[i]);
            countDiff[diff]++;
        }
        int m = countDiff.size();
        ll K = k1 + k2;
        for(ll i=m-1;i>0 && K>0;i--){
            int op = min((ll)countDiff[i],K);
            K -= op;
            countDiff[i] -= op;
            countDiff[i-1] += op;
        }
        ll ans = 0;
        for(ll i=m-1;i>=0;i--){       
            ans += (countDiff[i] * i * i);
        }
        return ans;
    }
};