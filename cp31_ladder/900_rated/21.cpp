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
        string s;
        cin>>s;

        int n=s.size();
        int ans=INT_MAX;
        
        // 00 case
        int si=-1;
        int ei=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0' && ei==n){
                ei=i;
            }else if(s[i]=='0' && ei!=n){
                si=i;
                break;
            }    
        }
        ans=min(ans,(n-1-ei)+(ei-si-1));
        // 25 case
        si=-1;
        ei=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='5' && ei==n){
                ei=i;
            }else if(s[i]=='2' && ei!=n){
                si=i;
                break;
            }
        }
        ans=min(ans,(n-1-ei)+(ei-si-1));

        // 75 case
        si=-1;
        ei=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='5' && ei==n){
                ei=i;
            }else if(s[i]=='7' && ei!=n){
                si=i;
                break;
            }
        }
        ans=min(ans,(n-1-ei)+(ei-si-1));

        // 50 case
        si=-1;
        ei=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0' && ei==n){
                ei=i;
            }else if(s[i]=='5' && ei!=n){
                si=i;
                break;
            }
        }
        ans=min(ans,(n-1-ei)+(ei-si-1));

        cout<<ans<<endl;   
    }
    
    return 0;
}