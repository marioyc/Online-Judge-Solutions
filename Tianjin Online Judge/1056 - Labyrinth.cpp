#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    int r,c,dist;
    
    node(){}
    
    node(int _r, int _c, int _dist){
        r = _r; c = _c; dist = _dist;
    }
}aux,aux2;

int R,C;
bool visited[1000][1000];
char M[1000][1001];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

node longestPath(int sr, int sc){
    int r,c;
    node ans = node(sr,sc,0);
    queue<node> Q;
    Q.push(node(sr,sc,0));
    
    memset(visited,false,sizeof(visited));
    visited[sr][sc] = true;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        ans = aux;
        
        for(int i=0;i<4;++i){
            r = aux.r+dr[i];
            c = aux.c+dc[i];
            
            if(r<0 || r>=R || c<0 || c>=C || M[r][c]!='.' || visited[r][c]) continue;
            visited[r][c] = true;
            Q.push(node(r,c,aux.dist+1));
        }
    }
    
    return ans;
}

int main(){
    int T,ans;
    scanf("%d", &T);
    bool found;
    
    while(T--){
        scanf ("%d %d",&C,&R);
        
        for(int i=0;i<R;++i) scanf("%s",M[i]);
        
        ans = 0; found = false;
        
        for(int i=0;i<R && !found;++i){
            for(int j=0;j<C && !found;++j){
                if(M[i][j]!='.') continue;
                found = true;
                
                aux2 = longestPath(i,j);
                printf("Maximum rope length is %d.\n",longestPath(aux2.r,aux2.c).dist);
            }
        }
    }
    
    return 0;
}

