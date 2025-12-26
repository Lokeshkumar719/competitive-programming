class Solution {
public:
    long long minMoves(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                sum+=nums[i];
            }
            if(nums[i]<0){
                idx=i;
            }
        }
        if(idx==-1){
            return 0;
        }
        if(idx!=-1){
            if(abs(nums[idx])>sum){
                return -1;
            }
        }

        long long ele=nums[idx];
        long long ans=0;
        int i=(idx-1+n)%n;
        int j=(idx+1)%n;
        // extraCnt is dis 
        int extraCnt=1;
        while(ele!=0){
            long long sum=nums[i]+nums[j];
            long long mini=min(abs(ele),sum);
            ans+=mini*extraCnt;
            ele+=mini;
            i=(i-1+n)%n;
            j=(j+1)%n;
            extraCnt++;
        }
        return ans;
    }
};