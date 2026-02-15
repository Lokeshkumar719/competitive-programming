class Solution {
public:
  int prefixConnected(vector<string>& words, int k) {
    int n=words.size();
    int cnt=0;
    map<string,int>mp;
    for(int i=0;i<n;i++){
      if(words[i].size()<k) continue;
      string s=words[i].substr(0,k);
      mp[s]++;
    }
    for(auto &it:mp){
      if(it.second>1) cnt++;
    }
    return cnt;
  }
};