class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(auto &ele:nums){
            mp[ele]++;
        }
        int ans=0;
        for(auto &it:mp){
            int freq=it.second;
            if(freq%k==0){
                ans+=(freq*it.first);
            }
        }
        return ans;
    }
};