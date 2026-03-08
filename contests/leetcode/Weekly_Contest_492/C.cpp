class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char mini=min_element(s.begin(),s.end())-s.begin();
        char maxi=*max_element(s.begin(),s.end())-s.begin();
        string t=s;
        sort(t.begin(),t.end());
        if(t==s) return 0;
        if(n==2) return -1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(t[i]==t[0]) cnt++;
        }
        bool flag=false;
        for(int i=1;i<n;i++){
            if(s[i]==maxi){
                flag=true;
                break;
            }
        }
        if(s[0]==mini || s[n-1]==maxi) return 1;
        if(s[n-1]==mini && cnt==1 && flag==false) return 3;
        return 2;
    }
};