#include <cstdio>
#include <cstring>

using namespace std;

int N,S[13],E[13][13],W[13][13],memo[(1<<12)];

int solve(int mask, int exp){
    int &ret = memo[mask];
    
    if(ret==-1){
        for(int i = 0;i+1<N;++i){
            if((mask & (1<<i))==0){
                int aux = (exp>S[i+1]? W[0][i+1] : 0)+solve(mask | (1<<i),exp+E[0][i+1]);
                if(aux>ret) ret = aux;
            }
        }
    }
    
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i)
            for(int j = 0;j<N;++j)
                scanf("%d",&E[i][j]);
        
        for(int i = 0;i<N;++i)
            for(int j = 0;j<N;++j)
                scanf("%d",&W[i][j]);
        
        for(int i = 0;i<N;++i) scanf("%d",&S[i]);
        
        memset(memo,-1,sizeof(memo));
        memo[(1<<(N-1))-1] = 0;
        
        printf("%d\n",N>1? solve(0,S[0]) : 0);
    }
    
    return 0;
}
