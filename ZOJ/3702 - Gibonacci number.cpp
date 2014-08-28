#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,i,Gi,j,lo,hi,mi;
    long long G[21];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&i,&Gi,&j);
        
        G[0] = 1;
        
        lo = 1; hi = 999999;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            G[1] = mi;
            
            for(int k = 2;k <= i;++k)
                G[k] = min(1000000LL,G[k - 1] + G[k - 2]);
            
            if(G[i] < Gi) lo = mi + 1;
            else hi = mi;
        }
        
        G[1] = lo;
        
        for(int k = 2;k <= max(i,j);++k)
            G[k] = G[k - 1] + G[k - 2];
        
        if(G[i] != Gi) printf("-1\n");
        else printf("%lld\n",G[j]);
    }
    
    return 0;
}
