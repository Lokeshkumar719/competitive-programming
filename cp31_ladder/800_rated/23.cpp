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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans=0;
        if( d<b || d<(c+b-a) ) cout<<-1<<endl;
        else{
            int x=d-(b-a);
            if(x>=c){
                ans+=abs(d-b);
                ans+=x-c;
                cout<<ans<<endl; 
            } else cout<<-1<<endl;   
        }
    }
    
    return 0;
}