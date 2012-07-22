#include <cstdio>

using namespace std;

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int a[K];
    
    for(int i = 0;i < K;++i)
        scanf("%d",&a[i]);
    
    int lo = 1,hi = N,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        int cont = 0;
        
        for(int i = 0;i < K;++i)
            cont += a[i] / mi;
        
        if(cont < N) hi = mi - 1;
        else lo = mi;
    }
    
    printf("%d\n",lo);
    
    for(int i = 0,j = 0;i < K && j < N;++i){
        while(a[i] >= lo && j < N){
            printf("%d\n",i + 1);
            a[i] -= lo;
            ++j;
        }
    }
    
    return 0;
}
