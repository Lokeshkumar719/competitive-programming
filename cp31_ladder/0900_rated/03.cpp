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
        int n,k,x;
        cin>>n>>k>>x;

        int lower=k*(k+1)/2;
        int upper=n*(n+1)/2-((n-k)*(n-k+1))/2;

        if(x<lower || x>upper) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}