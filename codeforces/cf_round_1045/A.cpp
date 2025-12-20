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
        int n,a,b;
        cin>>n>>a>>b;

        bool check=false;
        if((n-a)%2==0 || (n-b)%2==0){
            check=true;
        }

        if(!check){
            cout<<"NO"<<endl;
        }else{
            if(a>b){
                if((a-b)%2==0){
                    cout<<"YES"<<endl;
                } else{
                    cout<<"NO"<<endl;
                }
            }else{
                if((n-b)%2==0){
                    cout<<"YES"<<endl;
                } else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    
    return 0;
}