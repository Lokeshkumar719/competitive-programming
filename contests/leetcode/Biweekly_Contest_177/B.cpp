class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true){
            bool flag=false;
            vector<int>mp(26,-1);
            for(int i=0;i<s.size();i++){ 
                if(mp[s[i]-'a']!=-1 && i-mp[s[i]-'a']<=k){
                    s.erase(i,1);
                    flag=true;
                    break;
                }
                mp[s[i]-'a']=i;
            }
            if(!flag) return s;
        }
        return s;
    }
};