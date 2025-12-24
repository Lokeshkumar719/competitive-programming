class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=s.size();
        long long ans=1e16;
        map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(auto &it:mp){
            char ch=it.first;
            long long ct=0;
            for(int i=0;i<n;i++){
                if(s[i]!=ch){
                    ct+=cost[i];
                }
            }
            ans=min(ans,ct);
        }
        return ans;
    } 
};