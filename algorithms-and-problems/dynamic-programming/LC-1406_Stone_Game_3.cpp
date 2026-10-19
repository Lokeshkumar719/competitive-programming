class Solution {
public:
    int dp[50001][2];
    int getAliceScore(int i, vector<int>& piles, int turn) {
        if (i >= (int)piles.size())
            return 0;

        if (dp[i][turn] != -1)
            return dp[i][turn];

        int result = (turn) ? -1e9 : 1e9;
        int stones = 0;
        for (int x = 1; x <= 3; x++) {
            int idx = i + x - 1;
            if (idx >= piles.size())
                break;
            if (turn) {
                stones += piles[idx];
                result = max(result, stones + getAliceScore(idx + 1, piles, 0));
            } else {
                result = min(result, getAliceScore(idx + 1, piles, 1));
            }
        }

        return dp[i][turn] = (result != -1e9 && result != 1e9) ? result : 0;
    }
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        int alice_score = getAliceScore(0, piles, 1);
        cout << alice_score;
        int total = accumulate(begin(piles),end(piles),0);
        int bob_score = total - alice_score;
        if(alice_score  == bob_score)
            return "Tie";
        return (alice_score > bob_score)? "Alice" : "Bob";
    }
};