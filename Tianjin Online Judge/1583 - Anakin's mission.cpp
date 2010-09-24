#include <cstdio>
#include <cstring>

using namespace std;

double memo[51][101][101];

double solve(int N, int m, int n){
    if(N==0) return 1.0;
    if(memo[N][m][n]>-0.5) return memo[N][m][n];
    
    double aux = 0;
    
    if(m>0) aux += solve(N-1,m,n)+solve(N-1,m-1,n+1);
    if(n>0) aux += solve(N-1,m,n)+solve(N-1,m+1,n-1);
    aux /= 4;
    
    memo[N][m][n] = memo[N][n][m] = aux;
    return aux;
}

int main(){
    int T,N,m,n;
    scanf("%d",&T);
    
    memset(memo,-1,sizeof(memo));
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d %d",&N,&m,&n);
        printf("%.6lf\n",solve(N,m,n));
    }
    
    return 0;
}
