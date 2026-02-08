class Solution {
using ll=long long;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        map<ll,ll>mp;
        int l=0,r=0;
        ll ans=0;
        while(r<n){
            mp[nums[r]]++;
            ll cost=(mp.rbegin()->first - mp.begin()->first)*(ll)(r-l+1);
            while(cost>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);  
                l++; 
                cost=((mp.rbegin()->first - mp.begin()->first)*(ll)(r-l+1));
            }
            ans+=(ll)(r-l+1);
            r++;
        }
        return ans;
    }   
};