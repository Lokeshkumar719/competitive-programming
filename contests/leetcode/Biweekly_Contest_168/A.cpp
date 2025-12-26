class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        string orig=s;
        for(int k=1;k<=n;k++){
            reverse(s.begin(),s.begin()+k);
            string dup1=s;
            s=orig;
            reverse(s.begin()+n-k,s.end());
            string dup2=s;
            s=orig;
            ans=min({ans,dup1,dup2});
        }
        return ans;
    }
};