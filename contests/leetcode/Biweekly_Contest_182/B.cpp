class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int one=0,zero=0;
        for(auto &i:s){
            if(i=='1') one++;
            else zero++; 
        }
        int a=one;
        int b=zero;
        int c=(one>=1)? one-1:1;
        int d=INT_MAX;
        if(n>=2){
            int ones=0;
            for(int i=1;i<n-1;i++){
                if(s[i]=='1') ones++;
            }
            d=(s[0]!='1')+(s[n-1]!='1')+ones;
        }
        return min({a,b,c,d});
    }
};