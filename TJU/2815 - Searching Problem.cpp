#include<cstdio>
#include<cstring>
#include<deque>

using namespace std;

char map[50][51];
int R,C;
bool visited[50][50];

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

struct nodo{
    int r,c,cont;
    
    nodo(){
    }
    
    nodo(int _r, int _c, int _cont){
        r=_r;
        c=_c;
        cont=_cont;
    }
};

int bfs01(int r, int c){
    deque<nodo> Q;
    Q.push_back(nodo(r,c,0));
    nodo aux;
    
    for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
    visited[r][c]=true;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop_front();
        
        if(map[aux.r][aux.c]=='$') return aux.cont;
        
        for(int i=0;i<4;i++){
            r=aux.r+dr[i];
            c=aux.c+dc[i];
            
            if(r>=0 && r<R && c>=0 && c<C && !visited[r][c] && map[r][c]!='1'){
                if(map[r][c]=='D') Q.push_back(nodo(r,c,aux.cont+1));
                else Q.push_front(nodo(r,c,aux.cont));
                visited[r][c]=true;
            }
        }
    }
}

int main(){
    int r,c;
    
    while(1){
        scanf("%d %d",&R,&C);
        if(R==0 && C==0) break;
        
        for(int i=0;i<R;i++) scanf("%s",map[i]);
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(map[i][j]=='S'){
                    r=i;
                    c=j;
                }
        
        printf("%d\n",bfs01(r,c));
    }
    
    return 0;
}
