#include <cstdio>

using namespace std;

int pow(int a, int b, int MOD){
    int ret = 1,tmp,p = a;
    
    while(b){
        if(b & 1) ret = (ret*p)%MOD;
        p = (p*p)%MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int a,b,n,MOD;
    
    while(scanf("%d %d %d",&a,&b,&n)==3){
        MOD = 2*(a+b);
        
        if((n & 3)==2) printf("%d\n",MOD-1);
        else printf("%d\n",(2*pow(-(a-b)*(a-b)%MOD+MOD,n>>2,MOD)%MOD+MOD-1)%MOD);
    }
    
    return 0;
}
