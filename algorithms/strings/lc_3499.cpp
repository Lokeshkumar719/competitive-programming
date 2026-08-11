class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int prev=0;
        int i=0;
        int cnt1=0;
        while(i<n && s[i]=='0'){
            prev++;
            i++;
        }
        int maxi=0;
        while(i<n){
            while(i<n && s[i]=='1'){
                i++;
                cnt1++;
            }
            int curr=0;
            while(i<n && s[i]=='0'){
                curr++;
                i++;
            }
            // this one is important because one is surrounded only if we have prev and curr
            if(curr && prev) maxi=max(maxi,prev+curr);
            prev=curr;
        }
        return cnt1+maxi;
    }
};