#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int h[MAXN];

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&h[i]);
    
    int lo = 0,hi = 1000000000,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        long long aux = 0;
        
        for(int i = 0;i < N;++i)
            aux += max(0,h[i] - mi);
        
        if(aux < M) hi = mi - 1;
        else lo = mi;
    }
    
    printf("%d\n",lo);
    
    return 0;
}
