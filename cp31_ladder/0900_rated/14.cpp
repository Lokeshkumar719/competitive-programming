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
        int n;
        cin>>n;

        int minBus,maxBus;
        if(n&1 || n<4){
            cout<<-1<<endl;
            continue;
        } else{
            if(n%6==0 && n%4==0){
                cout<<n/6<<" "<<n/4<<endl;
            } else if(n%4==0 && n%6!=0){
                cout<<n/6+1<<" "<<n/4<<endl;
            } else if(n%6==0 && n%4!=0){
                cout<<n/6<<" "<<((n-6)/4)+1<<endl;
            } else{
                if(n%6==4)cout<<((n-4)/6)+1<<" "<<((n-6)/4)+1<<endl;
                else cout<<((n-8)/6)+2<<" "<<((n-6)/4)+1<<endl;
            }
        }

    }
    
    return 0;
}