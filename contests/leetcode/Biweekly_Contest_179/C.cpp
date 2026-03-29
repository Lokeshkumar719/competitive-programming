class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<bitset<1024>>prev(n),curr(n);
        prev[0][grid[0][0]]=1;
        for(int j=1;j<n;j++){
            for(int x=0;x<1024;x++){
                if(prev[j-1][x]){
                    prev[j][x^grid[0][j]]=1;
                }
            }
        }
        for(int i=1;i<m;i++){
            curr[0].reset();
            for(int x=0;x<1024;x++){
                if(prev[0][x]){
                    curr[0][x^grid[i][0]]=1;
                }
            }
            for(int j=1;j<n;j++){
                curr[j].reset();
                for(int x=0;x<1024;x++){
                    if(prev[j][x]){
                        curr[j][x^grid[i][j]]=1;
                    }
                    if(curr[j-1][x]){
                        curr[j][x^grid[i][j]]=1;
                    }
                }
            }
            prev=curr;
        }
        for(int x=0;x<1024;x++){
            if(prev[n-1][x]) return x;
        }
        return -1;
    }
};