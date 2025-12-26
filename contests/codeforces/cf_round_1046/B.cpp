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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        int i=0;
        while(s[i]=='0') i++;
        int cnt=0;
        bool check=true;
        while(i<n){
            if(s[i]=='1'){
                cnt++;
                if(cnt>=k){
                    check=false;
                    break;
                }
                i++;
            } else{
                while(i<n && s[i]=='0') i++;
                cnt=0;
            }
        }

        if(!check){
            cout<<"NO"<<endl;
            continue;
        } else{
            int mini=1;
            int maxi=n;
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    cout<<mini<<" ";
                    mini++;
                }else{
                    cout<<maxi<<" ";
                    maxi--;
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}