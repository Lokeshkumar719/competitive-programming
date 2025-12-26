class Solution {
public:
    int cntVowel(string word){
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                cnt++;
            }
        }
        return cnt;
    }
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);

        string ans="";
        string word;
        int cnt=0;
        int compi=0;
        while(ss>>word){
            int numVowel=cntVowel(word);
            if(cnt==0){
                ans+=word;
                ans+=" ";
                compi=numVowel;
                cnt++;
            }else{
                if(compi==numVowel){
                    reverse(word.begin(),word.end());
                    ans+=word;
                    ans+=" ";
                }else{
                    ans+=word;
                    ans+=" ";
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};