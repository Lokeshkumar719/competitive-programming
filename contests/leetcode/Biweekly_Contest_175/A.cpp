class Solution {
public:
  string reverseByType(string s) {
    int n=s.size();
    vector<char>v1,v2;
    for(int i=0;i<n;i++){
      if(s[i]<='z' && s[i]>='a') v1.push_back(s[i]);
      else v2.push_back(s[i]);
    }
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    int idx1=0,idx2=0;
    for(int i=0;i<n;i++){
      if(s[i]<='z' && s[i]>='a') s[i]=v1[idx1++];
      else s[i]=v2[idx2++];
    }
    return s;
  }
};