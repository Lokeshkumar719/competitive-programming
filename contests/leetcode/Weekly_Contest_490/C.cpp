class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.size();
        set<int>one;
        set<int>zero;
        for(int i=0;i<n;i++){
            if(t[i]=='1') one.insert(i);
            else zero.insert(i);
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='1' && t[i]=='1'){
                if(zero.size()){
                    ans+='1';
                    int idx=*(zero.begin());
                    zero.erase(idx);
                    swap(t[i],t[idx]);
                    one.insert(idx);
                    one.erase(i);
                }else ans+='0';
            }else if(s[i]=='0' && t[i]=='0'){
                if(one.size()){
                    ans+='1';
                    int idx=*(one.begin());
                    one.erase(idx);
                    swap(t[i],t[idx]);
                    zero.insert(idx);
                    zero.erase(i);
                }else ans+='0';
            }else{
                ans+='1';
                if(t[i]=='1')one.erase(i);
                else zero.erase(i);
            }
        }
        return ans;
    }
};