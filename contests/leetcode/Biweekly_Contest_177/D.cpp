class Solution {
using ll=long long;
ll mod=1e9+7;
public:
    ll binExpo(ll a,ll b,ll mod){
        ll ans=1LL;
        a%=mod;
        while(b){
            if(b&1){
                ans=((ans%mod)*(a%mod))%mod;
            }
            b>>=1;
            a=(a%mod*a%mod)%mod;
        }
        return ans;
    }
    int sumOfNumbers(ll l, ll r, ll k) {
        ll n=r-l+1;
        ll sum=(n*(l+r))/2;
        ll ans=1LL;
        ll a=binExpo(n,k-1,mod);
        ans=(ans%mod*a)%mod;
        ans=(ans*sum)%mod;
        ll x=(binExpo(10,k,mod)-1+mod)%mod;
        ans=(ans*x)%mod;
        ll invi=binExpo(9,mod-2,mod);
        ans=(ans*invi)%mod;
        return ans;
    }
};