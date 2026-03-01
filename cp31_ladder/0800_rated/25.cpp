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
        int i=0;
        int j=s.size()-1;
        bool flag=0;
        while(i<=j){
            if((s[i]=='0' && s[j]=='1') || (s[i]=='1' && s[j]=='0')){
                i++;
                j--;
            } else{
                flag=1;
                cout<<j-i+1<<endl;
                break;
            }
        }
        if(!flag){
            cout<<0<<endl;
        }   
    }
    
    return 0;
}