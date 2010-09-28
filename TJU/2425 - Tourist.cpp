#include<cstdio>
#include<algorithm>

using namespace std;

char map[101][101];
int memo[198][100][100];
int H,W,N;

int f(int n, int a, int b){
    if(n==N){
        if(map[H-1][W-1]=='*') return 1;
        return 0;
    }
    
    if(memo[n][a][b]==-1){
        int aux=0;
        
        if(a+1<H && b+1<H && map[a+1][n-a]!='#' && map[b+1][n-b]!='#') aux=max(aux,f(n+1,a+1,b+1));
        if(a+1<H && n-b+1<W && map[a+1][n-a]!='#' && map[b][n-b+1]!='#') aux=max(aux,f(n+1,a+1,b));
        if(n-a+1<W && b+1<H && map[a][n-a+1]!='#' && map[b+1][n-b]!='#') aux=max(aux,f(n+1,a,b+1));
        if(n-a+1<W && n-b+1<W && map[a][n-a+1]!='#' && map[b][n-b+1]!='#') aux=max(aux,f(n+1,a,b));
        
        if(map[a][n-a]=='*' && map[b][n-b]=='*'){
            if(a!=b) aux+=2;
            else aux+=1;
        }else if(map[a][n-a]=='*' || map[b][n-b]=='*') aux+=1;
        
        memo[n][a][b]=aux;
    }
    
    return memo[n][a][b];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&W,&H);
        
        N=H+W-2;
        
        for(int j=0;j<H;j++) scanf("%s",map[j]);
        
        for(int j=0;j<N;j++)
            for(int k=0;k<H;k++) fill(memo[j][k],memo[j][k]+H,-1);
        
        printf("%d\n",f(0,0,0));
    }
    
    return 0;
}
