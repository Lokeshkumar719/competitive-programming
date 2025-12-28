class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
      if(costBoth<cost1+cost2){
        long long both=(long long)min(need1,need2);
        long long ans=both*costBoth;
        
        int rem1=need1-both;
        int rem2=need2-both;

        long long  remCost1=(long long)min(cost1,costBoth)*(long long)rem1;
        long long remCost2=(long long)min(cost2,costBoth)*(long long)rem2;
        ans+=(remCost1+remCost2);
        return ans;
      }       
      long long cost=(long long)cost1*(long long)need1+(long long)cost2*(long long)need2;
      return cost;
    }   
};