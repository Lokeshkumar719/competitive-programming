class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)
            hash[i] = i;
        
        int idx = 0;
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i]){
                    if( dp[i] < (1+dp[j]) ){
                        dp[i] = 1+dp[j];
                        if(dp[i] > maxi){
                            maxi = dp[i];
                            idx = i;
                        }
                        hash[i] = j;
                    }
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[idx]);
        while(hash[idx] != idx){
            ans.push_back(arr[hash[idx]]);
            idx = hash[idx];
        }
        
        reverse(begin(ans),end(ans));
        
        return ans;
    
    }
};