class Solution {
public:
    int countSpecialIntegers(vector<int>& v) {
        int n =  v.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[v[i]].push_back(i);
        }
        int ans = 0;
        for(auto &it:mp){
            if(it.second.size()<3)
                continue;
            bool f = true;
            int diff = it.second[1] - it.second[0];
            for(int i =1; i<it.second.size();i++){
                if(it.second[i] - it.second[i-1]!= diff){
                    f = false;
                    break;
                }
            }
            if(f)
                ans++;
        }

        return ans;
    }
};