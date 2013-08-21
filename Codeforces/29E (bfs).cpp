#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 505

struct node{
    int pos1,pos2,par,dist;
    
    node(){}
    node(int _pos1, int _pos2, int _par, int _dist):
        pos1(_pos1), pos2(_pos2), par(_par), dist(_dist){}
};

vector<int> L[MAXN];
int parent[MAXN][MAXN][2];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(parent,-1,sizeof parent);
    queue<node> Q;
    
    Q.push(node(1,n,0,0));
    parent[1][n][0] = 0;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        
        if(cur.pos1 == n && cur.pos2 == 1 && cur.par == 0){
            int len = cur.dist / 2;
            printf("%d\n",len);
            
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
            
            for(int i = 0;i <= len;++i)
                printf("%d ",sol1[len - i]);
            printf("\n");
            for(int i = 0;i <= len;++i)
                printf("%d ",sol2[len - i]);
            printf("\n");
            return 0;
        }
        
        if(cur.par == 0){
            for(int i = L[cur.pos1].size() - 1,to;i >= 0;--i){
                to = L[cur.pos1][i];
                
                if(parent[to][cur.pos2][1] == -1){
                    parent[to][cur.pos2][1] = cur.pos1;
                    Q.push(node(to,cur.pos2,1,1 + cur.dist));
                }
            }
        }else{
            for(int i = L[cur.pos2].size() - 1,to;i >= 0;--i){
                to = L[cur.pos2][i];
                
                if(to != cur.pos1 && parent[cur.pos1][to][0] == -1){
                    parent[cur.pos1][to][0] = cur.pos2;
                    Q.push(node(cur.pos1,to,0,1 + cur.dist));
                }
            }
        }
    }
    
    printf("-1\n");
    
    return 0;
}
