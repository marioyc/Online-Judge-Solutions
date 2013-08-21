#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 10001

vector<int> L[MAXN],dir[MAXN];
int dist[MAXN][2];

struct node{
    int pos,dir,dist;
    
    node(){}
    node(int _pos, int _dir, int _dist):
        pos(_pos),dir(_dir),dist(_dist){}
};

int solve(int s, int e){
    memset(dist,-1,sizeof dist);
    deque<node> Q;
    
    Q.push_back(node(s,0,0));
    dist[s][0] = 0;
    Q.push_back(node(s,1,0));
    dist[s][1] = 0;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop_front();
        
        if(cur.pos == e) return cur.dist;
        
        for(int i = L[cur.pos].size() - 1,to;i >= 0;--i){
            to = L[cur.pos][i];
            int dir2 = dir[cur.pos][i];
            int dist2 = cur.dist + (dir2 != cur.dir? 1 : 0);
            
            if(dist[to][dir2] == -1 || dist2 < dist[to][dir2]){
                if(dist2 > cur.dist) Q.push_back(node(to,dir2,dist2));
                else Q.push_front(node(to,dir2,dist2));
                
                dist[to][dir2] = dist2;
            }
        }
    }
    
    return -1;
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        
        L[u].push_back(v);
        dir[u].push_back(0);
        
        L[v].push_back(u);
        dir[v].push_back(1);
    }
    
    int s,e;
    
    scanf("%d %d",&s,&e);
    
    printf("%d\n",solve(s,e));
    
    return 0;
}
