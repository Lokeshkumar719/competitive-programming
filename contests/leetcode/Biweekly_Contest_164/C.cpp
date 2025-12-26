class Solution {
public:
    int mod=1e9+7;
    int f(vector<vector<int>>& grid,int i,int j,int dirc,int m,int n,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][dirc]!=-1) return dp[i][j][dirc]%mod;
        long long ways=0;
        if(grid[i][j]==1){
            if(dirc==1){
                ways+=(f(grid,i+1,j,2,m,n,dp))%mod;
            }else if(dirc==2){
                ways+=(f(grid,i,j+1,1,m,n,dp)%mod);
            }
        }else{
             ways+=(f(grid,i,j+1,1,m,n,dp)%mod + f(grid,i+1,j,2,m,n,dp)%mod);
        }
        return dp[i][j][dirc]=ways%mod;   
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(4,-1)));
        f(grid,0,0,0,m,n,dp);
        return dp[0][0][0]%mod;
    }
};