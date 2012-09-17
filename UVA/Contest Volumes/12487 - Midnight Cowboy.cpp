#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int N,A,B,C;
long double M[100][101];
double eps = 1e-10;

long double solve(){
    for(int i = 0;i < N;++i){
        int ind = i;
        
        for(int j = i;j < N;++j)
            if(abs(M[j][i]) > eps)
                ind = j;
        
        for(int j = i;j <= N;++j)
            swap(M[i][j],M[ind][j]);
        
        long double aux = M[i][i];
        
        for(int j = i;j <= N;++j)
            M[i][j] /= aux;
        
        for(int j = i + 1;j < N;++j){
            aux = M[j][i];
            
            for(int k = i;k <= N;++k)
                M[j][k] -= aux * M[i][k];
        }
    }
    
    for(int i = N - 1;i > 0;--i){
        for(int j = i - 1;j >= 0;--j){
            long double aux = M[j][i];
            M[j][i] = 0;
            M[j][N] -= aux * M[i][N];
        }
    }
    
    return M[A][N];
}

int main(){
    bool adj[100][100];
    
    while(scanf("%d %d %d %d",&N,&A,&B,&C) == 4){
        --A; --B; --C;
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                M[i][j] = 0;
        
        memset(adj,false,sizeof adj);
        
        for(int i = 1,u,v;i < N;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            adj[u][v] = adj[v][u] = true;
        }
        
        for(int i = 0;i < N;++i){
            if(i == B){
                M[i][i] = 1;
                M[i][N] = 1;
            }else if(i == C){
                M[i][i] = 1;
                M[i][N] = 0;
            }else{
                M[i][i] = 1;
                
                int cont = 0;
                
                for(int j = 0;j < N;++j)
                    if(adj[i][j]) ++cont;
                
                for(int j = 0;j < N;++j)
                    if(adj[i][j]) M[i][j] = -1.0 / cont;
                
                M[i][N] = 0;
            }
        }
        
        printf("%.6Lf\n",solve() + eps);
    }
    
    return 0;
}
