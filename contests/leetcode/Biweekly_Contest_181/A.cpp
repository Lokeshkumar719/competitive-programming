class Solution {
public:
    bool validDigit(int n, int x) {
        if(n==0) return false;
        vector<int>dig;
        while(n){
            dig.push_back(n%10);
            n/=10;
        }
        if(dig.back()==x) return false;
        for(int i=0;i<dig.size();i++){
            if(dig[i]==x){
                return true;
            }
        }
        return false;
    }
};