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

        int cnt3=0;
        int cnt2=0;

        while(n>0 && n%2==0){
            cnt2++;
            n/=2;
        }

        while(n>0 && n%3==0){
            cnt3++;
            n/=3;
        }

        if(n>1 || cnt2>cnt3){
            cout<<-1<<endl;
        }else{
            cout<<(cnt3-cnt2)+cnt3<<endl;
        }

    }
    
    return 0;
}