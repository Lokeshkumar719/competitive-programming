class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')continue;
            else{
                for(int j=i;j>=0;j--){
                    ans+=s[j];
                }
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};