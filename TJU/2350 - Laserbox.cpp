#include <cstdio>

using namespace std;

int main(){
    int T,n,r,R,C;
    bool turn[50][50];
    bool visited[50][50][4];
    
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int dir;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&r);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                turn[i][j]=false;
        
        for(int i=0;i<r;i++){
            scanf("%d %d",&R,&C);
            R--; C--;
            turn[R][C]=true;
        }
        
        scanf("%d %d",&R,&C);
        R--; C--;
        
        if(R==n) dir=0;
        else if(C==-1) dir=1;
        else if(R==-1) dir=2;
        else dir=3;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<4;k++)
                    visited[i][j][k]=false;
        
        while(1){
            R+=dr[dir];
            C+=dc[dir];
            
            if(R==-1 || R==n || C==-1 || C==n){
                R++; C++;
                printf("%d %d\n",R,C);
                break;
            }
            
            if(visited[R][C][dir]){
                R++; C++;
                printf("0 0\n");
                break;
            }
            
            visited[R][C][dir]=true;
            
            if(turn[R][C]) dir=(dir+1)&3;
        }
    }
    
    return 0;
}
