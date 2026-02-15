class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
        map<int,int>mp;
        for(auto &i:bulbs){
            mp[i]++;
        }
        vector<int>ans;
        for(auto &it:mp){
            if(it.second&1){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};