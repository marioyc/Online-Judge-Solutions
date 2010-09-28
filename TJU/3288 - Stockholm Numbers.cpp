#include <cstdio>

using namespace std;

int main(){
    int T,K,n,x;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&K);
        
        for(n=0;K>(1<<n);K-=(1<<n),n++) ;
        K--;
        
        x=(1<<(n+1));
        
        for(int i=n-1;i>=0;i--)
            if(K>=(1<<i)){
                x|=(1<<(i+1));
                K-=(1<<i);
            }
        
        if((__builtin_popcount(x))&1) x|=1;
        
        printf("%d\n",x);
    }
    
    return 0;
}
