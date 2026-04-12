class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int deg=0;
            for(int j=0;j<n;j++){
                if(m[i][j]==1){
                    deg++;
                }
            }
            ans[i]=deg;
        }
        return ans;
    }
};