#include <cstdio>

using namespace std;

const int MOD = 200907;

long long pow(int a, int b){
    long long ans = 1,p = a;
    
    while(b!=0){
        if(b & 1) ans = (ans * p)%MOD;
        p = (p * p)%MOD;
        b >>= 1;
    }
    
    return ans;
}

int main(){
    int T,K;
    long long A,B,C,r,ans;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld %lld %d",&A,&B,&C,&K);
        
        if(C-B==B-A){
            r = B-A;
            ans = (A+(long long)(K-1)%MOD*(r%MOD)%MOD)%MOD;
        }else{
            r = B/A;
            ans = (A*pow(r%MOD,K-1))%MOD;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
