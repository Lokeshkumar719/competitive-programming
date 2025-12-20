class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        while(n){
            if(n&1){
                s='1'+s;
            }else s='0'+s;
            
            n/=2;
        }
        string a=s;
        int ans=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]!=a[i]) ans++;
        }
        return ans;
    }
};