#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 50000

int N,M,sum[MAX_N+1],memo[3][MAX_N];

int solve(int n, int s){
    if(n==3) return 0;
    if(memo[n][s]!=-1) return memo[n][s];
    
    int aux = 0,aux2;
    
    for(int i=s;i+M<=N;++i){
        aux2 = solve(n+1,i+M)+sum[i+M]-sum[i];
        if(aux2>aux) aux = aux2;
    }
    
    memo[n][s] = aux;
    return aux;
}

int main(){
    int T,p;
    sum[0] = 0;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&N);
        
        for(int i=0;i<N;++i){
            scanf("%d",&p);
            sum[i+1] = sum[i]+p;
        }
        
        scanf("%d",&M);
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,0));
    }
    
    return 0;
}
