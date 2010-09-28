#include<cstdio>
#include<queue>

using namespace std;

int M1[200][200];
int M2[200][200];
int N;

struct nodo{
    int r,c,dist;
    
    nodo(){
    }
    
    nodo(int _r, int _c, int _dist){
        r=_r;
        c=_c;
        dist=_dist;
    }
};

int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

bool visited[200][200];

int bfs(int r, int c){
    int x=-1,dist;
    
    queue<nodo> Q;
    Q.push(nodo(r,c,0));
    nodo aux;
    
    for(int i=0;i<N;i++) fill(visited[i],visited[i]+N,false);
    visited[r][c]=true;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(x!=-1 && aux.dist>dist) break;
        
        if(M1[aux.r][aux.c]!=0){
            if(x==-1){
                x=M1[aux.r][aux.c];
                dist=aux.dist;
                continue;
            }else return 0;
        }
        
        for(int i=0;i<4;i++){
            r=aux.r+di[i];
            c=aux.c+dj[i];
            
            if(r>=0 && r<N && c>=0 && c<N && !visited[r][c]){
                visited[r][c]=true;
                Q.push(nodo(r,c,aux.dist+1));
            }
        }
    }
    
    if(x==-1) return 0;
    else return x;
}

int main(){    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%d",&M1[i][j]);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(M1[i][j]!=0) M2[i][j]=M1[i][j];
            else M2[i][j]=bfs(i,j);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            printf("%d",M2[i][j]);
            if(j==N-1) printf("\n");
            else printf(" ");
        }
    
    return 0;
}
