class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        int a=s[0],b=s[1],c=s[2];
        if(a>=(b+c) || b>=(a+c) || c>=(b+a)) return {};

        double A=acos((b*b+c*c-a*a)/(2.0*(b*c)));
        double B=acos((a*a+c*c-b*b)/(2.0*(a*c)));
        double C=acos((b*b+a*a-c*c)/(2.0*(a*b)));

        const double PI=acos(-1.0);
        double aDeg=A*(180.0)/PI;
        double bDeg=B*(180.0)/PI;
        double cDeg=C*(180.0)/PI;
        
        vector<double>ans={aDeg,bDeg,cDeg};
        sort(ans.begin(),ans.end());
        return ans;
    }
};