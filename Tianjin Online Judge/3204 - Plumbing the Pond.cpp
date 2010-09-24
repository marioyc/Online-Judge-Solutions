#include <cstdio>

using namespace std;

int main(){
    int R,C;
    
    scanf("%d %d",&R,&C);
    
    int D[R][C];
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d",&D[i][j]);
    
    int dr[]={0,-1,-1,-1,0,1,1,1};
    int dc[]={-1,-1,0,1,1,1,0,-1};
    int r,c,ans=0;
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            if(D[i][j]==0) continue;
            
            for(int k=0;k<8;k++){
                r=i+dr[k];
                c=j+dc[k];
                
                if(r>=0 && r<R && c>=0 && c<C && D[i][j]==D[r][c]) ans>?=D[i][j];
            }
        }
    
    printf("%d\n",ans);
    
    return 0;
}
