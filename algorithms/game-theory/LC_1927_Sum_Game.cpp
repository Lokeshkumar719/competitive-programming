class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        int leftKnownSum = 0;
        int rightKnownSum = 0;
        int leftQnMark = 0;
        int rightQnMark = 0;
        for (int i = 0; i < n / 2; i++) {
            leftKnownSum += (s[i] != '?') ? s[i] - '0' : 0;
            leftQnMark += (s[i] == '?');
        }
        for (int i = n / 2; i < n; i++) {
            rightKnownSum += (s[i] != '?') ? s[i] - '0' : 0;
            rightQnMark += (s[i] == '?');
        }

        int total = leftQnMark + rightQnMark;

        if (total & 1)
            return true;
        
        return (2*leftKnownSum + 9*leftQnMark != 2*rightKnownSum + 9*rightQnMark);
    }
};