#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

struct node{
    int r,c;
    
    node(){}
    
    node(int _r, int _c){
        r = _r; c = _c;
    }
};

char M[1000][1001];
int R,C,r,c,r2,c2,dist;
int visited[1000][1001],head,tail;
bool done[1000][1000];
node Q[2000000];
int dr[] = {-1,0,0,1},dc[] = {0,-1,1,0};

int bfs(int rs, int cs, int re, int ce){
    memset(visited,-1,sizeof(visited));
    memset(done,false,sizeof(done));
    head = tail = 1000000;
    
    visited[rs][cs] = 0;
    Q[tail] = node(rs,cs); ++tail;
    
    while(head<tail){
        r = Q[head].r;
        c = Q[head].c;
        ++head;
        
        if(done[r][c]) continue;
        done[r][c] = true;
        
        if(r==re && c==ce) return visited[r][c];
        
        for(int i = 0;i<4;++i){
            r2 = r+dr[i]; c2 = c+dc[i];
            
            if(r2>=0 && r2<R && c2>=0 && c2<C){
                dist = visited[r][c]+(M[r2][c2]=='X'? 0 : 1);
                
                if(visited[r2][c2]==-1 || dist<visited[r2][c2]){
                    visited[r2][c2] = dist;
                    
                    if(M[r2][c2]=='X'){
                        --head;
                        Q[head] = node(r2,c2);
                    }else{
                        Q[tail] = node(r2,c2);
                        ++tail;
                    }
                }
            }
        }
    }
    
    return -1;
}

int main(){
    int rs,cs,re,ce;    
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R==0 && C==0) break;
        
        for(int i = 0;i<R;++i) scanf("%s",M[i]);
        
        scanf("%d %d %d %d",&rs,&cs,&re,&ce);
        --rs; --cs; --re; --ce;
        
        printf("%d\n",bfs(rs,cs,re,ce));
    }
    
    return 0;
}
