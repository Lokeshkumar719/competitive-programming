class Solution {
using ll=long long;
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<ll>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            ll ele=(ll)nums[i];
            while(ans.size() && ans.back()==ele){
                ll prev=(ll)ans.back();
                ans.pop_back();
                ele+=prev;
            }
            ans.push_back(ele);
        }
        return ans;
    }
};