#include <cstdio>

using namespace std;

int main(){
    int T,N;
    scanf("%d",&T);
    
    int type[100],I[100][2];
    double p[100];
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i){
            scanf("%d",&type[i]);
            if(type[i]!=0){
                scanf("%d %d",&I[i][0],&I[i][1]);
                --I[i][0]; --I[i][1];
            }
        }
        
        double eps = 1e-8,lo = 0,hi = 1,mi;
        
        for(int it = 0;it<30;++it){
            mi = (lo+hi)/2;
            
            for(int i = 0;i<N;++i){
                if(type[i]==0) p[i] = mi;
                else if(type[i]==1) p[i] = 1-(1-p[I[i][0]])*(1-p[I[i][1]]);
                else p[i] = p[I[i][0]]*p[I[i][1]];
            }
            
            if(p[N-1]>0.5-eps) hi = mi;
            else lo = mi;
        }
        
        printf("%.5f\n",lo);
    }
    
    return 0;
}
