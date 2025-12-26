class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.size();
        int a=0,b=0;
        for(char ch:s){
            if(ch=='a') a++;
            if(ch=='b') b++;
        }
        return abs(b-a);
    }
};