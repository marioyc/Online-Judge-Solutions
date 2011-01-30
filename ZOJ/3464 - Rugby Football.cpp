#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int TC,N,T,L,V[10000];
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d %d %d",&N,&T,&L);
        
        for(int i = 0;i<N;++i)
            scanf("%d",&V[i]);
        
        sort(V,V+N);
        
        double ans = 0;
        
        for(int i = N-1;i>=0;--i){
            if(T*V[i]>=L){
                ans += (double)L/V[i];
                L = 0;
            }else{
                ans += T;
                L -= T*V[i];
            }
        }
        
        if(L>0) puts("-1");
        else printf("%.2f\n",ans);
    }
    
    return 0;
}
