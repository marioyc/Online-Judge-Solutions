#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

struct node{
    int r,c,dir,dist;
    
    node(){}
    
    node(int _r, int _c, int _dir, int _dist) : r(_r), c(_c), dir(_dir), dist(_dist) {}
};

char M[1000][1001];
int dist[1000][1000][4];
int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < n;++i)
        scanf("%s",M[i]);
    
    memset(dist,-1,sizeof dist);
    
    deque<node> Q;
    Q.push_back(node(n - 1, m - 1,2,0));
    dist[n - 1][m - 1][2] = 0;
    
    int ans = -1;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop_front();
        
        if(cur.dist > dist[cur.r][cur.c][cur.dir]) continue;
        //printf("%d %d %d : %d\n",cur.r,cur.c,cur.dir,cur.dist);
        
        if(cur.r == 0 && cur.c == 0 && cur.dir == 2){
            ans = cur.dist;
            break;
        }
        
        if(M[cur.r][cur.c] == '#'){
            for(int k = 0;k < 4;++k){
                if(dist[cur.r][cur.c][k] == -1 || cur.dist + 1 < dist[cur.r][cur.c][k]){
                    Q.push_back(node(cur.r,cur.c,k,cur.dist + 1));
                    dist[cur.r][cur.c][k] = cur.dist + 1;
                }
            }
        }
        
        int r2 = cur.r + dr[cur.dir];
        int c2 = cur.c + dc[cur.dir];
        
        if(r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && (dist[r2][c2][cur.dir] == -1 || cur.dist < dist[r2][c2][cur.dir])){
            Q.push_front(node(r2,c2,cur.dir,cur.dist));
            dist[r2][c2][cur.dir] = cur.dist;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
