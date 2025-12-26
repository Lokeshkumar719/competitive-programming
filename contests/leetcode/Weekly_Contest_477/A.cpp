class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        int x=0;
        string a=to_string(n);
        string b="";
        long long sum=0;
        for(char ch:a){
            if(ch!='0'){
                b+=ch;
                sum+=(ch-'0');
            }
        }
        long long c=0;
        if(b!=""){
            c=stoll(b);
        }
        ans=c*sum;
        return ans;
    }
};