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
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        bool check1=true;
        bool check2=true;
        if(a>b){
            if(a>(2*b+2)){
                check1=false;
            }
        }else if(b>a){
            if(b>(2*a+2)){
                check1=false;
            }
        }

        int e=c-a;
        int f=d-b;

        if(e>f){
            if(e>(2*f+2)){
                check2=false;
            }
        } else if(f>e){
            if(f>(2*e+2)){
                check2=false;
            }
        }

        if(check1 && check2){
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;
    }
    
    return 0;
}