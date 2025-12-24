#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int32_t main() {
    fastio
    
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;
        
        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }

        int odd=0,even=0;
        for(int i=0;i<26;i++){
            if(hash[i]&1) odd++;
            else even++;
        }

        if((n-k)%2==0){
            if(k<odd){
                cout<<"NO"<<endl;
                continue;
            }
            k-=odd;
            if(k&1){
                cout<<"NO"<<endl;
            } else{
                cout<<"YES"<<endl;
            }
        } else{
            if(k<odd-1 || k==odd){
                cout<<"NO"<<endl;
                continue;
            }else if(k==odd-1){
                cout<<"YES"<<endl;
                continue;
            }
            k-=odd;
            if(k&1){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
        }
    }   

    
    return 0;
}