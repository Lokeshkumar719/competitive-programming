class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool check=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                check=1;
                break;
            }   
        }
        return (check)? 1:0;
    }
};