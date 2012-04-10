#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 2500

int parent[MAXN],rank[MAXN],cont[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        if(rank[x] < rank[y]){
            parent[x] = y;
            cont[y] += cont[x];
        }else{
            if(rank[x] == rank[y]) ++rank[x];
            parent[y] = x;
            cont[x] += cont[y];
        }
    }
}

int main(){
    int W,H;
    
    scanf("%d %d",&W,&H);
    
    char g[H][W + 1];
    
    for(int i = 0;i < H;++i)
        scanf("%s",g[i]);
    
    int N = W * H;
    
    for(int i = 0;i < N;++i){
        parent[i] = i;
        cont[i] = g[i / W][i % W] == 'G'? 1 : 0;
    }
    
    int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1},s;
    
    for(int i = 1;i + 1< H;++i)
        for(int j = 1;j + 1 < W;++j)
            if(g[i][j] == 'P') s = i * W + j;
    
    bool done[H][W];
    memset(done,false,sizeof done);
    
    for(int it = 0;it < N;++it){
        bool found = false;
        
        for(int i = 1;i + 1< H;++i){
            for(int j = 1;j + 1 < W;++j){
                if(g[i][j] != 'T' && g[i][j] != '#' && Find(i * W + j) == Find(s) && !done[i][j]){
                    bool trap = false;
                    
                    for(int k = 0;k < 4;++k){
                        int r2 = i + dr[k];
                        int c2 = j + dc[k];
                        
                        if(g[r2][c2] == 'T') trap = true;
                    }
                    
                    if(!trap){
                        found = true;
                        done[i][j] = true;
                        
                        for(int k = 0;k < 4;++k){
                            int r2 = i + dr[k];
                            int c2 = j + dc[k];
                            
                            Union(i * W + j,r2 * W + c2);
                        }
                    }
                }
            }
        }
        
        if(!found) break;
    }
    
    s = Find(s);
    
    printf("%d\n",cont[s]);
    
    return 0;
}
