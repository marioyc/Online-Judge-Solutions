#include <cstdio>
#include <cstring>

using namespace std;

int memo[2001][2001];

int solve(int n, int m){
    if(n==0 && m==0) return 1;
    if(memo[n][m]!=-1) return memo[n][m];
    
    int aux = 0;
    if(m==0) aux = solve(n-1,n-1);
    else aux = (solve(n-1,m-1)+solve(n,m-1))%10000;
    
    memo[n][m] = aux;
    return aux;
}

int main(){
    int n;
    memset(memo,-1,sizeof(memo));
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        int ans = solve(n,0);
        
        if(ans<10) printf("000%d",ans);
        else if(ans<100) printf("00%d",ans);
        else if(ans<1000) printf("0%d",ans);
        else printf("%d",ans);
        printf("\n");
    }
    
    return 0;
}
