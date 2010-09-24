#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int r,c,d;
    
    node(){
    }
    
    node(int _r, int _c, int _d){
        r=_r;
        c=_c;
        d=_d;
    }
}aux;

int main(){
    int T,n,m;
    bool visited[182][182];
    int ans[182][182];
    char M[182][183];
    queue<node> Q;
    int dr[]={-1,1,0,0},dc[]={0,0,-1,1},r,c;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",M[i]);
        
        for(int i=0;i<n;i++) fill(visited[i],visited[i]+m,false);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(M[i][j]=='1'){
                    Q.push(node(i,j,0));
                    visited[i][j]=true;
                    ans[i][j]=0;
                }
        
        while(!Q.empty()){
            aux=Q.front();
            Q.pop();
            
            for(int i=0;i<4;i++){
                r=aux.r+dr[i];
                c=aux.c+dc[i];
                
                if(r>=0 && r<n && c>=0 && c<m && !visited[r][c]){
                    visited[r][c]=true;
                    ans[r][c]=aux.d+1;
                    Q.push(node(r,c,aux.d+1));
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d",ans[i][j]);
                if(j==m-1) printf("\n");
                else printf(" ");
            }
        }
    }
    
    return 0;
}
