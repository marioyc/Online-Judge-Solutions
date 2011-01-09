#include <cstdio>

using namespace std;

int pow(int a, int b, int mod){
    int ret = 1,p = a;
    
    while(b){
        if(b & 1) ret = (ret*p)%mod;
        p = (p*p)%mod;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int N,M,Y;
    scanf("%d %d %d",&N,&M,&Y);
    Y %= M;
    
    bool found = false;
    
    for(int i = 0;i<M;++i){
        if(pow(i,N,M)==Y){
            printf("%d ",i);
            found = true;
        }
    }
    
    if(!found) puts("-1");
    
    return 0;
}
