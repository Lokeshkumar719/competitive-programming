class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n =nums.size();
        vector<int> ans = {-1,-1};
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i] + nums[j]) == target && nums[i] != nums[j]){
                    if(ans[0] == -1 && ans[1] == -1){
                        ans[0] = i;
                        ans[1] = j;
                    }else{
                        if((nums[ans[0]] * nums[ans[1]]) < (nums[i] * nums[j])){
                            ans[0] = i;
                            ans[1] = j;
                        }
                    }
                }
            }
        }
        if(ans[0]==-1 && ans[1] == -1)
            return ans;
        
        if(nums[ans[1]] > nums[ans[0]]){
            swap(ans[0],ans[1]);
        }
        
        return ans;
    }
};