#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct state{
    int r,c,dir,dist;
    
    state(){}
    
    state(int _r, int _c, int _dir, int _dist){
        r = _r; c = _c; dir = _dir;
        dist = _dist;
    }
};

int main(){
    int T,R,C,r0,c0;
    bool visited[100][100][4];
    char M[100][101];
    
    int dr[] = {-1,0,1,0},dc[] = {0,1,0,-1};
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i = 0;i<R;++i){
            scanf("%s",M[i]);
            
            for(int j = 0;j<C;++j){
                if(M[i][j]=='S'){
                    r0 = i;
                    c0 = j;
                }
            }
        }
        
        memset(visited,false,sizeof(visited));
        
        int ans = -1;
        queue<state> Q;
        Q.push(state(r0,c0,0,0));
        
        while(!Q.empty()){
            state aux = Q.front();
            Q.pop();
            
            if(M[aux.r][aux.c]=='T'){
                ans = aux.dist;
                break;
            }
            
            state aux2 = state(aux.r,aux.c,(aux.dir+1) & 3,aux.dist+1);
            
            if(!visited[aux2.r][aux2.c][aux2.dir]){
                visited[aux2.r][aux2.c][aux2.dir] = true;
                Q.push(aux2);
            }
            
            aux2 = state(aux.r,aux.c,(aux.dir+3) & 3,aux.dist+1);
            
            if(!visited[aux2.r][aux2.c][aux2.dir]){
                visited[aux2.r][aux2.c][aux2.dir] = true;
                Q.push(aux2);
            }
            
            
            aux2 = state(aux.r+dr[aux.dir],aux.c+dc[aux.dir],aux.dir,aux.dist+1);
            
            if(aux2.r>=0 && aux2.r<R && aux2.c>=0 && aux2.c<C && M[aux2.r][aux2.c]!='#' && !visited[aux2.r][aux2.c][aux2.dir]){
                visited[aux2.r][aux2.c][aux2.dir] = true;
                Q.push(aux2);
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
