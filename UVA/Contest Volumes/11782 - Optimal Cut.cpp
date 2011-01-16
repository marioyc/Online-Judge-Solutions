#include <cstdio>
#include <algorithm>

using namespace std;

int cost[(1<<20)-1],dp[2][(1<<19)][21];

void read(int n, int pos){
    scanf("%d",&cost[pos]);
    
    if(n>0){
        read(n-1,2*pos+1);
        read(n-1,2*pos+2);
    }
}

int main(){
    int H,K,aux;
    
    while(true){
        scanf("%d",&H);
        if(H==-1) break;
        
        scanf("%d",&K);
        read(H,0);
        
        if(H==0) printf("%d\n",cost[0]);
        else{
            for(int i = 0;i<(1<<H);++i)
                for(int j = 1;j<=K;++j)
                    dp[H & 1][i][j] = cost[(1<<H)-1+i];
            
            for(int i = H-1;i>=0;--i){
                for(int pos = 0;pos<(1<<i);++pos){
                    for(int j = 1;j<=K;++j){
                        aux = cost[(1<<i)-1+pos];
                        
                        for(int k = 1;k<j;++k)
                            aux = max(aux,dp[(i^1) & 1][2*pos][k]+dp[(i^1) & 1][2*pos+1][j-k]);
                        
                        dp[i & 1][pos][j] = aux;
                    }
                }
            }
            
            printf("%d\n",dp[0][0][K]);
        }
    }
    
    return 0;
}
