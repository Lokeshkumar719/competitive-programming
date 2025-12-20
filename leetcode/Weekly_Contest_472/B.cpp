class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            set<int>o;
            set<int>e;
            for(int j=i;j<n;j++){
                
                if(nums[j]&1){
                    o.insert(nums[j]);
                }else e.insert(nums[j]);

                if(o.size()==e.size()){
                    maxlen= max(maxlen,j-i+1);
                }
                
            }
        }
        return maxlen;
    }
};