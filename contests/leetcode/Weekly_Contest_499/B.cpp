class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'||s[i]=='u'){
                mp1[s[i]]++;
                if(mp2.find(s[i])==mp2.end()){
                    mp2[s[i]]=i;
                }
            }
        }
        vector<char>uni;
        for(auto &it:mp1){
            uni.push_back(it.first);
        }
        sort(uni.begin(),uni.end(),[&](char a,char b){
           if(mp1[a]!=mp1[b]) return mp1[a]>mp1[b];
            return mp2[a]<mp2[b];
        });
        vector<char>vowels;
        for(auto &ch:uni){
            for(int i=0;i<mp1[ch];i++){
                vowels.push_back(ch);
            }
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'||s[i]=='u'){
                s[i]=vowels[j++];
            }
        }
        return s;
    }
};