#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,f[100],g[100][100],h[100];
int memo[101][101];

int solve(int have, int last){
    int &ret = memo[have][last + 1];
    
    if(ret == -1){
        if(have == 0) ret = h[last];
        else{
            for(int i = last + 1;i < N;++i){
                int aux = solve(have - 1,i) + (last == -1? f[i] : g[last][i]);
                
                if(ret == -1 || aux < ret) ret = aux;
            }
        }
    }
    
    return ret;
}

int main(){
    int E;
    
    scanf("%d %d",&N,&E);
    
    int M[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&M[i]);
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < i;++j)
            f[i] += 2 * abs(M[j] - M[i]);
        
        for(int j = i + 1;j < N;++j)
            h[i] += 2 * abs(M[j] - M[i]);
        
        for(int j = i + 1;j < N;++j)
            for(int k = i + 1;k < j;++k)
                g[i][j] += abs(2 * M[k] - M[i] - M[j]);
    }
    
    memset(memo,-1,sizeof memo);
    
    for(int i = 1;i <= N;++i){
        if(solve(i,-1) <= E){
            printf("%d %d\n",i,solve(i,-1));
            break;
        }
    }
    
    return 0;
}
