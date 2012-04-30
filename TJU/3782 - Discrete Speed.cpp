#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;

struct node{
    int pos,v,prev;
    double dist;
    
    node(){}
    
    node(int _pos, int _v, int _prev, double _dist) : pos(_pos), v(_v), prev(_prev), dist(_dist) {}
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

int main(){
    int n,m,s,e,dist[31][31],sp[31][31];
    bool visited[31][31][31];
    double best[31][31][31];
    
    while(true){
        scanf("%d %d",&n,&m);
        
        if(n == 0) break;
        
        scanf("%d %d",&s,&e);
        
        memset(dist,-1,sizeof dist);
        
        for(int i = 0,u,v,w,x;i < m;++i){
            scanf("%d %d %d %d",&u,&v,&w,&x);
            dist[u][v] = dist[v][u] = w;
            sp[u][v] = sp[v][u] = x;
        }
        
        priority_queue<node> Q;
        
        memset(visited,false,sizeof visited);
        bool found = false;
        
        for(int i = 1;i <= n;++i)
            for(int j = 0;j <= 30;++j)
                for(int k = 1;k <= n;++k)
                    best[i][j][k] = 1e10;
        
        Q.push(node(s,0,s,0));
        best[s][0][s] = 0;
        
        while(!Q.empty()){
            node cur = Q.top();
            Q.pop();
            
            if(visited[cur.pos][cur.v][cur.prev]) continue;
            visited[cur.pos][cur.v][cur.prev] = true;
            
            if(cur.pos == e && cur.v == 1){
                printf("%.6f\n",cur.dist);
                found = true;
                break;
            }
            
            for(int dv = -1;dv <= 1;++dv)
                for(int i = 1;i <= n;++i)
                    if(dist[cur.pos][i] != -1 && i != cur.prev && cur.v + dv > 0 && cur.v + dv <= sp[cur.pos][i] && !visited[i][cur.v + dv][cur.pos])
                        if(cur.dist + (double)dist[cur.pos][i] / (cur.v + dv) < best[i][cur.v + dv][cur.pos]){
                            Q.push(node(i,cur.v + dv,cur.pos,cur.dist + (double)dist[cur.pos][i] / (cur.v + dv)));
                            best[i][cur.v + dv][cur.pos] = cur.dist + (double)dist[cur.pos][i] / (cur.v + dv);
                        }
        }
        
        if(!found) puts("unreachable");
    }
    
    return 0;
}
