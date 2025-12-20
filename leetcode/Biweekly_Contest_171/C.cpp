class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        long long ans=0;
        int size=0;
        vector<int>diff;
        for(int i=0;i<n;i++){
            if(t1[i]>=t2[i]){
                size++;
                ans+=t1[i];
            }else{
                diff.push_back(t1[i]-t2[i]);
                ans+=t2[i];
            }
        }
        if(size>=k) return ans;
        sort(diff.begin(),diff.end(),[](int a,int b){
            return a>b;
        });
        for(int i=0;i<k-size;i++){
            ans+=diff[i];
        }
        return ans;
         
    }
};