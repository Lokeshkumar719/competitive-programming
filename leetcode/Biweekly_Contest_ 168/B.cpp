class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int dig=9;
        string ans="";
        while(sum>0){
            if(dig<=sum){
                int n=sum/dig;
                for(int i=0;i<n;i++){
                    ans+=to_string(dig);
                } 
                sum-=n*dig;
            }else dig--;
        }
        if(ans.size()<num){
            for(int i=0;i<ans.size()-num;i++){
                ans+='0';
            }
        }
        return ans.size()==num? ans:"";
    }
};