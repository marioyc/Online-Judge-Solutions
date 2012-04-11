#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int N,X,Y,sX,sY,eX,eY;
int dist[1000][1000],dist2[1000][1000];
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};

int dijkstra(int D){
    queue< pair<int, int> > Q;
    memset(dist2,-1,sizeof dist2);
    
    Q.push(make_pair(sX,sY));
    dist2[sX][sY] = 0;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        
        for(int i = 0;i < 4;++i){
            int x2 = cur.first + dx[i];
            int y2 = cur.second + dy[i];
            
            if(x2 >= 0 && x2 < X && y2 >= 0 && y2 < Y && dist[x2][y2] >= D && dist2[x2][y2] == -1){
                Q.push(make_pair(x2,y2));
                dist2[x2][y2] = 1 + dist2[cur.first][cur.second];
            }
        }
    }
    
    return dist2[eX][eY];
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&X,&Y);
        scanf("%d %d %d %d",&sX,&sY,&eX,&eY);
        
        queue< pair<int, int> > Q;
        memset(dist,-1,sizeof dist);
        
        for(int i = 0,x,y;i < N;++i){
            scanf("%d %d",&x,&y);
            Q.push(make_pair(x,y));
            dist[x][y] = 0;
        }
        
        while(!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            
            for(int i = 0;i < 4;++i){
                int x2 = cur.first + dx[i];
                int y2 = cur.second + dy[i];
                
                if(x2 >= 0 && x2 < X && y2 >= 0 && y2 < Y && dist[x2][y2] == -1){
                    Q.push(make_pair(x2,y2));
                    dist[x2][y2] = 1 + dist[cur.first][cur.second];
                }
            }
        }
        
        int lo = 0,hi = dist[sX][sY],mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(dijkstra(mi) != -1) lo = mi;
            else hi = mi - 1;
        }
        
        printf("%d %d\n",lo,dijkstra(lo));
    }
    
    return 0;
}
