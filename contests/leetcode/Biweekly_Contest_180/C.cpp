class Solution {
using ll=long long;
public:
    bool isPrime(int n){
  if(n<=1)return false;
  if(n<=3)return true;
  if(n%2==0||n%3==0)return false;
  for(int i=5;i*i<=n;i+=6){
    if(n%i==0||n%(i+2)==0)return false;
  }
  return true;
}
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>primes;
        int maxi=1e5+100;
        for(int i=2;i<=maxi;i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        ll ans=0LL;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(!isPrime(nums[i])){
                    int ele=*upper_bound(primes.begin(),primes.end(),nums[i]);
                    ans+=(ll)(ele-nums[i]);
                }
            }else{
                if(isPrime(nums[i])){
                    if(nums[i]!=2)
                        ans+=1;
                    else ans+=2;
                }
            }
        }
        return ans;
    }
};