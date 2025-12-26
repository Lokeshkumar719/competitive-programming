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
#include <unordered_set>
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
        unordered_set<int>s;
        vector<int>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
            s.insert(v[i]);
        }
        vector<int>helper;
        for(int i=1;i<=n;i++){
            if(!s.count(i)){
                helper.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                v[i]=helper.back();
                helper.pop_back();
            }
        }
        int si=0,ei=0;
        for(int i=0;i<n;i++){
            if(v[i]!=(i+1)){
                si=i;
                ei=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(v[i]!=(i+1)){
                ei=i;
                break;
            }
        }
        if(si==0 && ei==0){
            cout<<0<<endl;
        }else{
            cout<<ei-si+1<<endl;
        }
        
    }
    return 0;
}