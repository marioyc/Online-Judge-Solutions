#include <cstdio>

using namespace std;

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    long long sum = 0;
    
    int a[M];
    
    for(int i = 0;i < M;++i)
        scanf("%d",&a[i]);
    
    int lo = 0,hi = 1000000001,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        long long cont = 0;
        
        for(int i = 0;i < M;++i)
            cont += (a[i] + mi - 1) / mi;
        
        if(cont <= N) hi = mi;
        else lo = mi + 1;
    }
    
    printf("%d\n",lo);
    
    return 0;
}
