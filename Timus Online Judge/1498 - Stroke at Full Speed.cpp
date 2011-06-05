#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    int r,c,dist;
    
    node(){}
    
    node(int _r, int _c, int _dist){
        r = _r; c = _c; dist = _dist;
    }
}aux,Q[10000];

int N,M,L,dist[100][100];

int solve(int x, int y, int dx, int dy){
    if(dist[x][y] == -1) return 0;
    
    int ret = 0;
    
    for(int i = 0;;++i){
        int x2 = x + i * dx,y2 = y + i * dy;
        
        if(x2 >=0 && x2 < N && y2 >= 0 && y2 < M && dist[x2][y2] != -1 && dist[x2][y2] + i <= L)
            ret = i + 1;
        else
            break;
    }
    
    return ret;
}

int main(){
    
    scanf("%d %d %d",&N,&M,&L);
    
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    --x1; --y1; --x2; --y2;
    
    int head = 0,tail = 0;
    int dr[] = {-1,0,0,1},dc[] = {0,-1,1,0};
    
    memset(dist,-1,sizeof(dist));
    dist[x1][y1] = 0; dist[x2][y2] = L + 1;
    Q[tail++] = node(x1,y1,0);
    
    while(head < tail){
        aux = Q[head++];
        
        if(aux.dist == L) continue;
        
        for(int i = 0,x2,y2;i < 4;++i){
            x2 = aux.r + dr[i];
            y2 = aux.c + dc[i];
            
            if(x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && dist[x2][y2] == -1){
                dist[x2][y2] = aux.dist + 1;
                Q[tail++] = node(x2,y2,dist[x2][y2]);
            }
        }
    }
    
    int ans = 0;
    
    if(x2 > 0) ans = max(max(ans,solve(x2 - 1,y2,-1,0)), max(solve(x2 - 1,y2,0,-1), solve(x2 - 1,y2,0,1)));
    if(x2 + 1 < N) ans = max(max(ans,solve(x2 + 1,y2,1,0)), max(solve(x2 + 1,y2,0,-1), solve(x2 + 1,y2,0,1)));
    if(y2 > 0) ans = max(max(ans,solve(x2,y2 - 1,0,-1)), max(solve(x2,y2 - 1,-1,0), solve(x2,y2 - 1,1,0)));
    if(y2 + 1 < M) ans = max(max(ans,solve(x2,y2 + 1,0,1)), max(solve(x2,y2 + 1,-1,0), solve(x2,y2 + 1,1,0)));
    
    printf("%d\n",ans);
    
    return 0;
}
