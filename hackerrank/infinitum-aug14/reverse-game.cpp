#include <cstdio>

using namespace std;

int main(){
    int T,N,K;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&K);
        
        for(int i = 0;i < N;++i)
            if(K >= i) K = i + N - 1 - K;
        
        printf("%d\n",K);
    }
    
    return 0;
}
