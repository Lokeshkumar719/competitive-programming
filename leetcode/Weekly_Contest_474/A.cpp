class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,mini=INT_MAX;
        for(auto &ele:nums){
            maxi=max(maxi,ele);
            mini=min(mini,ele);
        }
        
        set<int>s(nums.begin(),nums.end());
        vector<int>v;
        for(int i=mini;i<=maxi;i++){
            if(!s.count(i))v.push_back(i);
        }
        sort(v.begin(),v.end());
        return v;
    }
};