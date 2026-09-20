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
            if(it.second.size() > 3 || it.second.size()<3)
                continue;
            if(2*it.second[1] == (it.second[0]+it.second[2])) ans++;
        }

        return ans;
    }
};