class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0;
        int sum = 0;
        for(int i=0;i<k;i++)
            sum += cardPoints[i];
        
        int ans = sum;
        int st = k-1;
        int end = n-1;
        for(int st = k-1;st>=0;st--){
            sum -= cardPoints[st];
            sum += cardPoints[end--];
            ans = max(ans,sum);
        }

        return ans;
    }
};