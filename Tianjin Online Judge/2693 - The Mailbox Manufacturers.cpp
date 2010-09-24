#include <cstdio>
#include <algorithm>

using namespace std;

int memo[11][101][101];

int solve(int n, int a, int b){
    if(a>b) return 0;
    if(memo[n][a][b]!=-1) return memo[n][a][b];
    
    if(n==1) memo[n][a][b]=b*(b+1)/2-(a-1)*a/2;
    else{
        int aux=INT_MAX;
        for(int i=a;i<=b;i++) aux=min(aux,i+max(solve(n-1,a,i-1),solve(n,i+1,b)));
        memo[n][a][b]=aux;
    }
    
    return memo[n][a][b];
}

int main(){
    int T,k,m;
    
    scanf("%d",&T);
    
    memset(memo,-1,sizeof(memo));
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&k,&m);
        
        printf("%d\n",solve(k,1,m));
    }
}
