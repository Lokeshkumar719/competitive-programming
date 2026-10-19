class Solution {
public:
    void addOthers(vector<int>&cnt,string &ans){
        for(int i=0;i<26;i++){
            if(!cnt[i]) continue;
            for(int j=0;j<cnt[i];j++){
                ans.push_back(i+'a');
            }
        }
    }
    bool solve(string &target,int idx,string &ans,vector<int>&cnt){
        if(idx == target.length()){
            return false;
        }
        char ch = target[idx];
        if(cnt[ch-'a']){
            ans.push_back(ch);
            cnt[ch-'a']--;
            if(solve(target,idx+1,ans,cnt)) return true;
            ans.pop_back();
            cnt[ch-'a']++;
        }
        for(char letter=(char)(ch+1);letter<='z';letter++){
            if(cnt[letter-'a']){
                ans.push_back(letter);
                cnt[letter-'a']--;
                addOthers(cnt,ans);
                return true;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>cnt(26,0);
        for(auto &ch:s){
            cnt[ch-'a']++;
        }
        string ans;
        solve(target,0,ans,cnt);
        return ans;
    }
};