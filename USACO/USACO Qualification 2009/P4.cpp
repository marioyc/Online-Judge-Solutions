/*
ID:zion_ba1
LANG:C++
TASK:papaya
*/

#include <iostream>

using namespace std;

int main(){
    freopen("papaya.in","r",stdin);
    freopen("papaya.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int R,C;
    
    scanf("%d %d",&R,&C);
    
    int M[R][C];
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d",&M[i][j]);
    
    int r=0,c=0;
    bool visited[R][C];
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            visited[i][j]=false;
    
    const int dr[]={-1,1,0,0};
    const int dc[]={0,0,-1,1};
    int ans=M[0][0];
    
    while(r!=R-1 || c!=C-1){
        int ind=-1,mx=0;
        
        for(int i=0;i<4;i++){
            int r2=r+dr[i],c2=c+dc[i];
            if(r2<0 || r2>=R || c2<0 || c2>=C || visited[r2][c2]) continue;
            
            if(M[r2][c2]>mx){
                mx=M[r2][c2];
                ind=i;
            }
        }
        
        r+=dr[ind];
        c+=dc[ind];
        ans+=mx;
        
        if(!(r<0 || r>=R || c<0 || c>=C)) visited[r][c]=true;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
