#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long mod_pow(int a, int b){
    long long ret = 1,p = a;
    
    while(b!=0){
        if(b & 1) ret = (ret*p)%MOD;
        b >>= 1;
        p = (p*p)%MOD;
    }
    
    return (int)ret;
}

long long inv(int n){
    return mod_pow(n,MOD-2);
}

int main(){
    int n;
    cin>>n;
    
    long long ans = 0,C = 1;
    
    for(int s = n;s>=0;--s){
        ans = (ans + C*s%MOD)%MOD;
        
        int i = 2*n-2-s;
        
        C = C*(i+1)%MOD;
        C = C*inv(i+1-n+2)%MOD;
    }
    
    ans = ((ans*2%MOD-n)%MOD + MOD)%MOD;
    cout<<ans<<endl;
    
    return 0;
}
