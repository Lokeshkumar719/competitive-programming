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

        string s;
        cin>>s;

        int cnt=1;
        int maxlen=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
                maxlen=max(maxlen,cnt);
            } else{
                cnt=1;
            }
        }
    
        cout<<maxlen+1<<endl;
    }
    
    return 0;
}