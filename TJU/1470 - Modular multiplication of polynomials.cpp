#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,f[1000],g[1000],h[1000],p[1999];
    int d1,d2,d3,D;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&d1);
        --d1;
        for(int i=d1;i>=0;--i) scanf("%d",&f[i]);
        
        scanf("%d",&d2);
        --d2;
        for(int i=d2;i>=0;--i) scanf("%d",&g[i]);
        
        scanf("%d",&d3);
        --d3;
        for(int i=d3;i>=0;--i) scanf("%d",&h[i]);
        
        memset(p,0,sizeof(p));
        for(int i=0;i<=d1;++i) for(int j=0;j<=d2;++j) p[i+j] ^= (f[i] & g[j]);
        
        for(int i=d1+d2;i>=d3;--i){
            if(p[i]==0) continue;
            for(int j=0;j<=d3;++j) p[i-j] ^= h[d3-j];
        }
        
        D = d3-1;
        while(D>1 && p[D]==0) --D;
        
        printf("%d",D+1);
        for(int i=D;i>=0;--i) printf(" %d",p[i]);
        printf("\n");
    }
    
    return 0;
}
