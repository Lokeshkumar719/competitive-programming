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
        int a,b,c;
        cin>>a>>b>>c;

        if(2*b==a+c){
            cout<<"YES"<<endl;
        } else if(2*b>(a+c)){
            if(((2*b-a)%c)==0 || (((2*b-c)%a)==0)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            if((a+c)%(2*b)==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
    return 0;
}