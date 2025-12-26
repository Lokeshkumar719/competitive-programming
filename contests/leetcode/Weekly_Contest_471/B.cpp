class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int freq=mp[s[i]];
                bool check=true;
                for(auto &it:mp){
                    if(it.second!=freq){
                        check=false;
                        break;
                    }
                }
                if(check){
                    maxlen=max(maxlen,j-i+1);
                }
            }  
        }

        return maxlen;
    }
};