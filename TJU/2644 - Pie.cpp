#include<cstdio>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    int T,N,F;
    int r[10000];
    double vol[10000];
    double lo,hi,mi;
    int cont;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&F);
        
        for(int j=0;j<N;j++) scanf("%d",&r[j]);
        for(int j=0;j<N;j++) vol[j]=PI*r[j]*r[j];
        
        lo=0; hi=314159266;
        
        for(int j=0;j<45;j++){
            mi=(lo+hi)/2;
            
            cont=0;
            
            for(int k=0;k<N;k++) cont+=floor(vol[k]/mi);
            
            if(cont>=F+1) lo=mi;
            else hi=mi;
        }
        
        printf("%.4f\n",lo);
    }
    
    return 0;
}
