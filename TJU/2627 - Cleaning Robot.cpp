#include <cstdio>
#include <algorithm>
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

char M[20][21];
int R,C,dist[11][11];
bool visited[20][20];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int bfs(int &r1, int &c1, int &r2, int &c2){
    queue<node> Q;
    Q.push(node(r1,c1,0));
    
    for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
    visited[r1][c1]=true;
    
    int r,c;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux.r==r2 && aux.c==c2) return aux.d;
        
        for(int i=0;i<4;i++){
            r=aux.r+dr[i];
            c=aux.c+dc[i];
            
            if(r>=0 && r<R && c>=0 && c<C && M[r][c]!='x' && !visited[r][c]){
                visited[r][c]=true;
                Q.push(node(r,c,aux.d+1));
            }
        }
    }
    
    return -1;
}

int main(){
    int r[11],c[11],ind[11],N;
    
    for(int i=0;i<11;i++) ind[i]=i;
    
    while(1){
        scanf("%d %d",&C,&R);
        if(C<=0) break;
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        N=1;
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(M[i][j]=='o'){
                    r[0]=i;
                    c[0]=j;
                }else if(M[i][j]=='*'){
                    r[N]=i;
                    c[N]=j;
                    N++;
                }
            }
        }
        
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                dist[i][j]=dist[j][i]=bfs(r[i],c[i],r[j],c[j]);
        
        int ans=-1,aux,d;
        bool valid;
        
        do{
            aux=0;
            valid=true;
            
            for(int i=0;i<N-1 && valid;i++){
                d=dist[ind[i]][ind[i+1]];
                if(d==-1) valid=false;
                aux+=d;
            }
            
            if(!valid) continue;
            if(ans==-1) ans=aux;
            else ans<?=aux;
        }while(next_permutation(ind+1,ind+N));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
