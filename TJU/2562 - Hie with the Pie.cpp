#include <cstdio>
#include <cstring>

using namespace std;

int n,M[11][11],memo[11][(1<<11)];

int solve(int cur, int mask){
    if(memo[cur][mask]!=-1) return memo[cur][mask];
    
    int aux = -1;
    
    if(mask==(1<<n)-1) aux = M[cur][0];
    else{
        for(int j=0;j<n;++j)
            if((mask & (1<<j))==0 && (aux==-1 || aux>M[cur][j]+solve(j,mask | (1<<j))))
                aux = M[cur][j]+solve(j,mask | (1<<j));
    }
    
    memo[cur][mask] = aux;
    return aux;
}

int main(){
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        ++n;
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&M[i][j]);
        
        for(int k=0;k<n;++k) for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            if(M[i][k]+M[k][j]<M[i][j]) M[i][j] = M[i][k]+M[k][j];
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,1));
    }
    
    return 0;
}

