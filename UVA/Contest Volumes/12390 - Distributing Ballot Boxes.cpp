#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,B,a[500000];
    
    while(true){
        scanf("%d %d",&N,&B);
        if(N == -1) break;
        
        int lo = 1,hi = 0,mi;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&a[i]);
            hi = max(hi,a[i]);
        }
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            int cont = 0;
            
            for(int i = 0;i < N;++i)
                cont += (a[i] + mi - 1) / mi;
            
            if(cont > B) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
