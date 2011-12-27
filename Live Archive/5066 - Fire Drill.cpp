#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
    int f,r,c,dist;
    
    node(){}
    
    node(int _f, int _r, int _c, int _dist){
        f = _f; r = _r; c = _c; dist = _dist;
    }
};

char M[10][100][101];
int f[100],r[100],c[100],p[100];
int rs,cs,dist[10][100][100];
int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};
int memo[100][3334];

int solve(int n, int t){
    if(n == -1) return 0;
    
    int &ret = memo[n][t];
    
    if(ret == -1){
        ret = solve(n - 1,t);
        
        if(dist[f[n]][r[n]][c[n]] != -1 && dist[f[n]][r[n]][c[n]] <= t)
            ret = max(ret,p[n] + solve(n - 1,t - dist[f[n]][r[n]][c[n]]));
    }
    
    return ret;
}

int main(){
    int TC,F,R,C,N,T;
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d %d %d %d %d",&F,&R,&C,&N,&T);
        T /= 3;
        
        for(int i = 0;i < F;++i)
            for(int j = 0;j < R;++j)
                scanf("%s",M[i][j]);
        
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                if(M[0][i][j] == 'S'){
                    rs = i;
                    cs = j;
                }
            }
        }
        
        memset(dist,-1,sizeof dist);
        
        queue<node> Q;
        
        dist[0][rs][cs] = 0;
        Q.push(node(0,rs,cs,0));
        
        while(!Q.empty()){
            node aux = Q.front();
            Q.pop();
            
            if(M[aux.f][aux.r][aux.c] == 'U' && dist[aux.f + 1][aux.r][aux.c] == -1){
                dist[aux.f + 1][aux.r][aux.c] = aux.dist + 1;
                Q.push(node(aux.f + 1,aux.r,aux.c,aux.dist + 1));
            }
            
            if(M[aux.f][aux.r][aux.c] == 'D'  && dist[aux.f - 1][aux.r][aux.c] == -1){
                dist[aux.f - 1][aux.r][aux.c] = aux.dist + 1;
                Q.push(node(aux.f - 1,aux.r,aux.c,aux.dist + 1));
            }
            
            for(int k = 0,r2,c2;k < 4;++k){
                r2 = aux.r + dr[k];
                c2 = aux.c + dc[k];
                
                if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && dist[aux.f][r2][c2] == -1 && M[aux.f][r2][c2] != 'X'){
                    dist[aux.f][r2][c2] = aux.dist + 1;
                    Q.push(node(aux.f,r2,c2,aux.dist + 1));
                }
            }
        }
        
        for(int i = 0;i < N;++i){
            scanf("%d %d %d %d",&f[i],&r[i],&c[i],&p[i]);
            --f[i]; --r[i]; --c[i];
        }
        
        memset(memo,-1,sizeof memo);
        printf("%d\n",solve(N - 1,T));
    }
    
    return 0;
}
