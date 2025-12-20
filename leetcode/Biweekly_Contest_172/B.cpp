// v0 which leaves a remainder 0 when divide by 0
// v1 which leaves a remainder 0 when divide by 1
// v2 which leaves a remainder 0 when divide by 2
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>v0;
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(nums[i]%3==0){
                v0.push_back(nums[i]);
            }else if(nums[i]%3==1){
                v1.push_back(nums[i]);
            }else{
                v2.push_back(nums[i]);
            }
        }
        sort(v0.begin(),v0.end(),[](int a,int b){
            return a>b;
        });
        sort(v1.begin(),v1.end(),[](int a,int b){
            return a>b;
        });
        sort(v2.begin(),v2.end(),[](int a,int b){
            return a>b;
        });
        int ans=0;
        if(v0.size()>=3){
            ans=max(ans,v0[0]+v0[1]+v0[2]);
        }
        if(v1.size()>=3){
            ans=max(ans,v1[0]+v1[1]+v1[2]);
        }
        if(v2.size()>=3){
            ans=max(ans,v2[0]+v2[1]+v2[2]);
        }
        if(v0.size() && v1.size() && v2.size()){
            ans=max(ans,v0[0]+v1[0]+v2[0]);
        }
        return ans;    
    }
};