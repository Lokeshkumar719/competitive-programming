class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<bool>isTaken(26,false);
        vector<int>lastIdx(26,0);
        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a']=i;
        }
        string ans;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isTaken[ch-'a']) continue;
            while(ans.size() && ans.back()>ch && lastIdx[ans.back()-'a']>i ){
                isTaken[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            isTaken[ch-'a']=true;
        }
        return ans;
    }
};