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
    // gcd(a,b)=gcd(a-b,b);
    // so max gcd we can get is a-b that us |a-b|
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<" "<<0<<endl;
            continue;
        }
        int diff=abs(a-b);

        if(a>b){
            // making b the closest multiple of diff
            cout<<diff<<" "<<min(b%diff,diff-b%diff)<<endl;
        }else{
            cout<<diff<<" "<<min(a%diff,diff-a%diff)<<endl;
        }
    }
    return 0;
}