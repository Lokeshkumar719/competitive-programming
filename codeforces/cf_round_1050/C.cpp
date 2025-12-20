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
        int n,m;
        cin>>n>>m;

        int prevA=0;
        int prevB=0;
        int ans=0;
        while(n--){
            int a,b;
            cin>>a>>b;

            int time=a-prevA;
            int postion=abs(prevB-b);

            if(time&1){
                if(postion){
                    ans+=time;
                }else{
                    ans+=time-1;
                }
            }else{
                if(postion){
                    ans+=time-1;
                }else{
                    ans+=time;
                }
            }

            prevA=a;
            prevB=b;
        }

        ans+=(m-prevA);
        cout<<ans<<endl;
    }
    
    return 0;
}