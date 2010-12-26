#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

struct state{
    int x,y,dist;
    
    state(){}
    
    state(int _x, int _y, int _dist){
        x = _x; y = _y; dist = _dist;
    }
}aux;

bool wall[200][200][4],door[200][200][4];
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0},visited[200][200];

int bfs(int xe, int ye){
    if(xe<=0 || ye<=0 || xe>=200 || ye>=200) return 0;
    memset(visited,-1,sizeof(visited));
    deque<state> Q;
    
    Q.push_front(state(0,0,0));
    visited[0][0] = 0;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop_front();
        
        if(aux.x==xe && aux.y==ye) return aux.dist;
        if(visited[aux.x][aux.y]<aux.dist) continue;
        
        for(int i = 0;i<4;++i){
            int x = aux.x+dx[i],y = aux.y+dy[i];
            
            if(x>=0 && x<200 && y>=0 && y<200 && (!wall[aux.x][aux.y][i] || door[aux.x][aux.y][i])){
                int dist = aux.dist+(door[aux.x][aux.y][i]? 1 : 0);
                
                if(visited[x][y]==-1 || dist<visited[x][y]){
                    visited[x][y] = dist;
                    
                    if(door[aux.x][aux.y][i]) Q.push_back(state(x,y,dist));
                    else Q.push_front(state(x,y,dist));
                }
            }
        }
    }
    
    return -1;
}

int main(){
    int M,N;
    double xe,ye;
    
    while(true){
        scanf("%d %d",&M,&N);
        if(M<0) break;
        
        memset(wall,false,sizeof(wall));
        memset(door,false,sizeof(door));
        
        for(int i = 0,x,y,d,t;i<M;++i){
            scanf("%d %d %d %d",&x,&y,&d,&t);
            
            if(d==0){
                for(int i = 0;i<t;++i){
                    wall[x+i][y-1][0] = true;
                    wall[x+i][y][2] = true;
                }
            }else{
                for(int i = 0;i<t;++i){
                    wall[x-1][y+i][1] = true;
                    wall[x][y+i][3] = true;
                }
            }
        }
        
        for(int i = 0,x,y,d;i<N;++i){
            scanf("%d %d %d",&x,&y,&d);
            
            if(d==0){
                door[x][y-1][0] = true;
                door[x][y][2] = true;
            }else{
                door[x-1][y][1] = true;
                door[x][y][3] = true;
            }
        }
        
        scanf("%lf %lf",&xe,&ye);
        printf("%d\n",bfs((int)xe,(int)ye));
    }
    
    return 0;
}
