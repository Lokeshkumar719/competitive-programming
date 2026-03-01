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
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() {
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
        map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            sum+=(v[i]);
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen,i-mp[sum]);
            } else{
                mp[sum]=i;
            }
        }
        cout<<maxlen<<endl;
    }
    return 0;
}