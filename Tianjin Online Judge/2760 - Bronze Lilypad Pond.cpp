#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int r,c,t;
    
    node(){
    }
    
    node(int _r, int _c, int _t){
        r=_r;
        c=_c;
        t=_t;
    }
};

int main(){
    int M,N,M1,M2;
    
    scanf("%d %d %d %d",&M,&N,&M1,&M2);
    
    int X[M][N],rs,cs,re,ce;
    
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&X[i][j]);
            
            if(X[i][j]==3){
                rs=i;
                cs=j;
            }else if(X[i][j]==4){
                re=i;
                ce=j;
            }
        }
    
    node aux;
    int r,c,t,r2,c2;
    
    bool visited[M][N];
    for(int i=0;i<M;i++) fill(visited[i],visited[i]+N,false);
    
    bool valid[M][N];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(X[i][j]==0 || X[i][j]==2) valid[i][j]=false;
            else valid[i][j]=true;
    
    queue<node> Q;
    Q.push(node(rs,cs,0));
    visited[rs][cs]=true;
    
    int dr[]={-1,-1,1,1};
    int dc[]={1,-1,1,-1};
    
    while(1){
        aux=Q.front();
        Q.pop();
        
        r=aux.r;
        c=aux.c;
        t=aux.t;
        
        if(r==re && c==ce){
            printf("%d\n",t);
            break;
        }
        
        for(int i=0;i<4;i++){
            r2=r+dr[i]*M1; c2=c+dc[i]*M2;
            if(r2>=0 && r2<M && c2>=0 && c2<N && valid[r2][c2] && !visited[r2][c2]){
                Q.push(node(r2,c2,t+1));
                visited[r2][c2]=true;
            }
        }
        
        for(int i=0;i<4;i++){
            r2=r+dr[i]*M2; c2=c+dc[i]*M1;
            if(r2>=0 && r2<M && c2>=0 && c2<N && valid[r2][c2] && !visited[r2][c2]){
                Q.push(node(r2,c2,t+1));
                visited[r2][c2]=true;
            }
        }
    }
    
    return 0;
}
