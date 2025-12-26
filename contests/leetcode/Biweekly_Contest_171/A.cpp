class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i<=(n/2+1);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        if(num==1 || num==4 || num==6 || num==8 || num==9) return false;
        if(num==2 || num==3 || num==5 || num==7) return true;
        
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<=n-1;i++){
            int a=stoi(s.substr(0,i+1));
            string x=s.substr(i+1);
            int b=2;
            if(x!="")b=stoi(x);
            if(isPrime(a)==false || isPrime(b)==false) return false;
        }
        return true;
    }
};