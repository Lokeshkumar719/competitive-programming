class Solution {
public:
    int getTime(string &t) {
        string s1,s2,s3;
        s1=t.substr(0,2);
        s2=t.substr(3,2);
        s3=t.substr(6,2);
        int seconds=0;
        seconds+=(stoi(s1)*3600);
        seconds+=(stoi(s2)*60);
        seconds+=(stoi(s3));
        return seconds;
    }
    int secondsBetweenTimes(string s1, string s2) { 
        return abs(getTime(s1)-getTime(s2));
      }
};