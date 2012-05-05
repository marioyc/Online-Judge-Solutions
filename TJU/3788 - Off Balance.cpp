#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int parent[600],sum[600],l[600],r[600],n[600];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        parent[x] = y;
        
        sum[y] += sum[x];
        
        if(l[x] != -1){
            if(l[y] == -1){
                l[y] = l[x];
                r[y] = r[x];
            }else{
                l[y] = min(l[y],l[x]);
                r[y] = max(r[y],r[x]);
            }
        }
    }
}

int main(){
    int w,h;
    char M[60][11];
    
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    
    vector<int> L[600];
    int in[600],Q[600],head,tail;
    bool inq[600],done[600][600];
    
    while(true){
        scanf("%d %d",&w,&h);
        
        if(w == 0) break;
        
        for(int i = 0;i < h;++i)
            scanf("%s",M[i]);
        
        int N = w * h;
        int cont = 0;
        
        for(int i = 0;i < N;++i){
            int y = i / w,x = i % w;
            
            parent[i] = i;
            sum[i] = 2*x + 1;
            l[i] = r[i] = -1;
            
            if(M[y][x] != '.'){
                ++cont;
                
                if(y == h - 1 || (M[y + 1][x] != '.' && M[y + 1][x] != M[y][x])){
                    l[i] = 2*x;
                    r[i] = 2*x + 2;
                }
            }
        }
        
        for(int i = 0;i < h;++i){
            for(int j = 0;j < w;++j){
                if(M[i][j] != '.'){
                    for(int k = 0;k < 4;++k){
                        int y = i + dr[k];
                        int x = j + dc[k];
                        
                        if(y >= 0 && y < h && x >= 0 && x < w && M[y][x] == M[i][j])
                            Union(i*w + j,y*w + x);
                    }
                }
            }
        }
        
        memset(in,0,sizeof in);
        
        for(int i = 0;i < N;++i)
            L[i].clear();
        
        for(int i = 0;i + 1 < h;++i){
            for(int j = 0;j < w;++j){
                if(M[i][j] != '.' && M[i + 1][j] != '.' && M[i + 1][j] != M[i][j]){
                    L[ Find(i * w + j) ].push_back( Find((i + 1) * w + j) );
                    ++in[ Find((i + 1) * w + j) ];
                }
            }
        }
        
        memset(inq,false,sizeof inq);
        head = tail = 0;
        
        for(int i = 0;i < h;++i)
            for(int j = 0;j < w;++j)
                if(M[i][j] != '.' && in[ Find(i * w + j)] == 0 && !inq[ Find(i * w + j) ]){
                    Q[tail++] = Find(i * w + j);
                    inq[ Find(i * w + j) ] = true;
                }
        
        while(head < tail){
            int cur = Q[head++];
            
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                
                --in[to];
                
                if(in[to] == 0)
                    Q[tail++] = to;
            }
        }
        
        memset(done,false,sizeof done);
        
        for(int i = 0;i < tail;++i) n[ Q[i] ] = 1;
        
        for(int i = 0,cur;i < tail;++i){
            cur = Q[i];
            
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                
                if(done[cur][to]) continue;
                done[cur][to] = true;
                
                sum[to] += sum[cur];
                n[to] += n[cur];
            }
        }
        
        bool ok = true;
        
        for(int i = 0;i < h;++i)
            for(int j = 0;j < w;++j)
                if(M[i][j] != '.' && parent[i*w + j] == i*w + j)
                    if(sum[i*w + j] <= 4 * n[i * w + j] * l[i*w + j] || sum[i*w + j] >= 4 * n[i * w + j] * r[i*w + j])
                        ok = false;
        
        puts(ok? "STABLE" : "UNSTABLE");
    }
    
    return 0;
}
