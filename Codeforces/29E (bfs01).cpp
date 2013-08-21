#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define MAXN 505

struct node{
    int pos1,pos2,par,dist;
    
    node(){}
    node(int _pos1, int _pos2, int _par, int _dist):
        pos1(_pos1), pos2(_pos2), par(_par), dist(_dist){}
};

vector<int> L[MAXN];
int dist[MAXN][MAXN][2];
int parent[MAXN][MAXN][2];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(dist,-1,sizeof dist);
    deque<node> Q;
    
    Q.push_back(node(1,n,0,0));
    dist[1][n][0] = 0;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop_front();
        
        if(cur.dist > dist[cur.pos1][cur.pos2][cur.par]) continue;
        
        if(cur.pos1 == n && cur.pos2 == 1 && cur.par == 0){
            printf("%d\n",cur.dist);
            
            int pos1 = n,pos2 = 1;
            
            vector<int> sol1,sol2;
            sol1.push_back(n);
            sol2.push_back(1);
            
            while(pos1 != 1 || pos2 != n){
                pos2 = parent[pos1][pos2][0];
                pos1 = parent[pos1][pos2][1];
                
                sol1.push_back(pos1);
                sol2.push_back(pos2);
            }
            
            for(int i = 0;i <= cur.dist;++i)
                printf("%d ",sol1[cur.dist - i]);
            printf("\n");
            for(int i = 0;i <= cur.dist;++i)
                printf("%d ",sol2[cur.dist - i]);
            printf("\n");
            return 0;
        }
        
        if(cur.par == 0){
            for(int i = L[cur.pos1].size() - 1,to;i >= 0;--i){
                to = L[cur.pos1][i];
                
                if(dist[to][cur.pos2][1] == -1 || 1 + cur.dist < dist[to][cur.pos2][1]){
                    dist[to][cur.pos2][1] = 1 + cur.dist;
                    parent[to][cur.pos2][1] = cur.pos1;
                    Q.push_back(node(to,cur.pos2,1,1 + cur.dist));
                }
            }
        }else{
            for(int i = L[cur.pos2].size() - 1,to;i >= 0;--i){
                to = L[cur.pos2][i];
                
                if(to != cur.pos1 && (dist[cur.pos1][to][0] == -1 || cur.dist < dist[cur.pos1][to][0])){
                    dist[cur.pos1][to][0] = cur.dist;
                    parent[cur.pos1][to][0] = cur.pos2;
                    Q.push_front(node(cur.pos1,to,0,cur.dist));
                }
            }
        }
    }
    
    printf("-1\n");
    
    return 0;
}
