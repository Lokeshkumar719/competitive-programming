class Solution {
using ll=long long;
public:
    ll cost=0;
    void f(int n){
        if(n==1) return;
        ll a=(ll)n/2;
        ll b=(ll)n-a;
        cost+=(a*b);
        f(a);
        f(b);
    }
    int minCost(int n) {
        if(n==1) return 0;
        ll a=(ll)n/2;
        ll b=(ll)n-a;
        cost+=(a*b);
        f(a);
        f(b);
        return cost;
    }
};