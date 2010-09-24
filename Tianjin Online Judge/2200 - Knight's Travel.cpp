#include <cstdio>

using namespace std;

int main(){
    int n,m,a,b,c,d;
    int dp[50][50];
    
    int dr[]={1,1,2,2};
    int dc[]={2,-2,1,-1};
    int R,C;
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        
        scanf("%d %d %d %d",&a,&b,&c,&d);
        
        a--; b--; c--; d--;
        
        for(int i=a;i<=c;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=0;
        
        dp[a][b]=1;
        
        for(int i=a;i<c;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<4;k++){
                    R=i+dr[k];
                    C=j+dc[k];
                    
                    if(R>c || C<0 || C>=m) continue;
                    
                    dp[R][C]+=dp[i][j];
                }
        printf("%d\n",dp[c][d]);
    }
    
    return 0;
}
