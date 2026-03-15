class Solution {
using ll=long long;
public:
  long long countCommas(long long n) {
    ll a=(ll)1e3;
    ll b=(ll)1e6;
    ll c=(ll)1e9;
    ll d=(ll)1e12;
    ll e=(ll)1e15;
    if(n<a) return 0;
    ll ans=0LL;
    ans+=min(n,b-1)-a+1;
    if(n>=b)ans+=(min(n,c-1)-b+1)*2LL;
    if(n>=c)ans+=(min(n,d-1)-c+1)*3LL;
    if(n>=d)ans+=(min(n,e-1)-d+1)*4LL;
    if(n>=e) ans+=(n-e+1)*5LL;
    return ans;
  }
};