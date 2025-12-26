class Solution {
public:
    bool scoreBalance(string s) {
        int n=s.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=s[i]-96;
        }
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        for(int i=0;i<n;i++){
            if((2*v[i])==v[n-1]){
                return true;
            }
        }
        return false;
    }
};