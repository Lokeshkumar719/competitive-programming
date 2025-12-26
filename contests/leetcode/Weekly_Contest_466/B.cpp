class Solution {
public:
  int minOperations(string s) {
    int n=s.size();
    char mini='z'+1;
    for(int i=0;i<n;i++){
        if(s[i]!='a' && s[i]<mini){
          mini=s[i];
        }
    }
    return (mini!='z'+1)? ('z'-mini+1):0;  
  }
};