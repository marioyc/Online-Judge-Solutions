#include <cstdio>
#include <cstring>

using namespace std;

int dx0[] = {-1,0,0,1,1,1},dy0[] = {0,1,-1,1,0,-1};
int dx1[] = {-1,-1,-1,0,0,1},dy1[] = {1,0,-1,1,-1,0};
int memo[15][29][29];

int solve(int n, int x, int y){
    if(n==0){
        if(x==0 && y==0) return 1;
        return 0;
    }
    
    if(memo[n][x+14][y+14]!=-1) return memo[n][x+14][y+14];
    
    int aux = 0;
    
    if(y%2==0) for(int i=0;i<6;++i) aux += solve(n-1,x+dx0[i],y+dy0[i]);
    else for(int i=0;i<6;++i) aux += solve(n-1,x+dx1[i],y+dy1[i]);
    
    memo[n][x+14][y+14] = aux;
    return aux;
}

int main(){
    int T,n;
    scanf("%d",&T);
    
    memset(memo,-1,sizeof(memo));
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        printf("%d\n",solve(n,0,0));
    }
    
    return 0;
}
