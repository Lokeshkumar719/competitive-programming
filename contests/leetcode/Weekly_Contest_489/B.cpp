class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp1;
        for(auto &ele:nums){
            mp1[ele]++;
        }
        // count freqency of frequency
        map<int,int>mp2;
        for(auto &it:mp1){
            mp2[it.second]++;
        }
        for(auto &ele:nums){
            int freq=mp1[ele];
            int freq_freq=mp2[freq];
            if(freq_freq==1){
                return ele;
            }
        }
        return -1;
    }
};