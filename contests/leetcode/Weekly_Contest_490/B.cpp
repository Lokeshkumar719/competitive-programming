class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string s=to_string(n);
        int sum=0;
        for(auto &ch:s){
            int dig=ch-'0';
            int fact=1;
            for(int i=dig;i>=1;i--){
                fact*=i;
            }
            sum+=fact;
        }
        vector<int>v1(10);
        vector<int>v2(10);
        for(auto &ch:s){
            v1[ch-'0']++;
        }
        while(sum){
            int dig=(sum%10);
            v2[dig]++;
            sum/=10;
        }
        return (v1==v2);
    }
};