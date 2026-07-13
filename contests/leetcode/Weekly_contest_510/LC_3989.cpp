class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,1);
        int ans=1;
        for(int col=0;col<n;col++){
            for(int prev=0;prev<col;prev++){
                bool flag=true;
                for(int row=0;row<m;row++){
                    if(abs(grid[row][prev]-grid[row][col])>limit){
                        flag=false;
                    }
                }
                if(flag){
                    dp[col]=max(dp[col],1+dp[prev]);
                    ans=max(ans,dp[col]);
                }
            }
        }
        return ans;
    }
};