class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        int len=2;
        int maxlen=len;
        int i=2;
        while(i<n){
            if(v[i]==(v[i-1]+v[i-2])){
                len++;
                maxlen=max(maxlen,len);  
            }else{
                len=2;
            }
            i++; 
        }
        return maxlen;
    }
};