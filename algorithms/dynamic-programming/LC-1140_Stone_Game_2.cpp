class Solution {
public:
    int dp[101][101][2];
    int getAliceScore(int i, int M, vector<int> &piles, int turn){
        if(i >= (int) piles.size()) 
            return 0;
            
        if(dp[i][M][turn] != -1)
            return dp[i][M][turn];

        int result = (turn)? -1 : 1e9;
        int stones = 0; 
        for(int x = 1; x <= 2*M; x++){
            int idx = i + x - 1;
            if(idx >= piles.size()) break;
            if(turn){
                stones += piles[idx];
                result = max(result ,stones + getAliceScore(idx+1, max(x,M), piles, 0));
            }else{
                result = min(result,getAliceScore(idx+1,max(x,M),piles, 1));
            }
        }

        return  dp[i][M][turn] = (result != -1 && result != 1e9) ? result : 0;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        int alice_score = getAliceScore(0,1,piles,1);
        return alice_score;
    }
};