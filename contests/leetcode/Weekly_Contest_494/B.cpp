class Solution {
using ll=long long;
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int odd=INT_MAX,even=-1;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                odd=min(odd,nums[i]);
                break;
            }else if(nums[i]%2==0){
                even=nums[i];
            }
        }
        if(odd==INT_MAX || even==-1) return true;
        bool allEven=true;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                if(nums[i]-odd<1){
                    allEven=false;
                    break;
                }
            }
        }
        bool allOdd=true;
        for(int i=0;i<n;i++){
            if(!(nums[i]&1)){
                if(nums[i]-odd<1){
                    allOdd=false;
                    break;
                }
            }
        }
        return (allOdd|allEven);
    }
};