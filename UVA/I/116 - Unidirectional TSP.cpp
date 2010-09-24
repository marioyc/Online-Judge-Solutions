#include<cstdio>
#define INT_MAX 2147483647

using namespace std;

int main(){
    int M[10][100];
    int dp[10][100];
    int next[10][99];
    int r,c,aux,cur,x;
    
    while(scanf("%d %d",&r,&c)==2){
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) scanf("%d",&M[i][j]);
        
        for(int i=0;i<r;i++) dp[i][c-1]=M[i][c-1];
        
        for(int i=c-2;i>=0;i--)
            for(int j=0;j<r;j++){
                cur=INT_MAX;
                
                for(int k=-1;k<=1;k++){
                    aux=(j+k+r)%r;
                    
                    if(dp[aux][i+1]<cur || (dp[aux][i+1]==cur && aux<next[j][i])){
                        cur=dp[aux][i+1];
                        next[j][i]=aux;
                    }
                }
                
                dp[j][i]=M[j][i]+cur;
            }
        
        aux=INT_MAX;
        
        for(int i=0;i<r;i++)
            if(dp[i][0]<aux){
                aux=dp[i][0];
                x=i;
            }
        
        printf("%d",x+1);
        for(int i=0;i<c-1;i++){
            x=next[x][i];
            printf(" %d",x+1);
        }        
        printf("\n%d\n",aux);
    }
    
    return 0;
}
