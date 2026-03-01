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

        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int>twos(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]==2){
                cnt++;
            }
            twos[i]=cnt;
        }
        bool isFound=false;
        for(int i=0;i<n;i++){
            if(twos[i]==(twos[n-1]-twos[i])){
                cout<<i+1<<endl;
                isFound=true;
                break;
            }
        }
        if(!isFound) cout<<-1<<endl;
    }
    
    return 0;
}