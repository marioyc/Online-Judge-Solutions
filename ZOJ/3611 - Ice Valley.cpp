#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
char M[500][501];
bool in[500][500];
int er[500][500],ec[500][500],ed[500][500];

void dfs(int r, int c){
    if(er[r][c] != -1) return;
    if(M[r][c] == '0' || M[r][c] == 'W' || M[r][c] == '$' || M[r][c] == '#'){
        er[r][c] = r;
        ec[r][c] = c;
        ed[r][c] = 0;
    }else{
        int r2,c2;
        
        if(M[r][c] == 'L'){
            r2 = r;
            c2 = c - 1;
        }else if(M[r][c] == 'R'){
            r2 = r;
            c2 = c + 1;
        }else if(M[r][c] == 'D'){
            r2 = r + 1;
            c2 = c;
        }else{
            r2 = r - 1;
            c2 = c;
        }
        
        if(r2 == n || r2 == -1 || c2 == -1 || c2 == m || in[r2][c2]){
            er[r][c] = -2;
            ec[r][c] = -2;
        }else{
            in[r][c] = true;
            dfs(r2,c2);
            in[r][c] = false;
            er[r][c] = er[r2][c2];
            ec[r][c] = ec[r2][c2];
            ed[r][c] = ed[r2][c2] + 1;
        }
    }
}

struct node{
    int r,c,mask,dist;
    
    node(){}
    
    node(int _r, int _c, int _mask, int _dist):
        r(_r), c(_c), mask(_mask), dist(_dist){}
    
    bool operator < (node X) const{
        return dist > X.dist;
    }
};

int x1,y1,x2,y2,id[500][500],id2[110 + 10],dist[110 + 10][1 << 10];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int dijkstra(){
    memset(dist,-1,sizeof dist);
    priority_queue<node> Q;
    Q.push(node(x1,y1,0,0));
    dist[ id[x1][y1] ][0] = 0;
    
    int best = -1,t = -1;
    
    while(!Q.empty()){
        node aux = Q.top();
        Q.pop();
        
        if(dist[ id[aux.r][aux.c] ][aux.mask] != aux.dist) continue;
        if(aux.r == x2 && aux.c == y2){
            int ntreasure = __builtin_popcount(aux.mask);
            
            if(ntreasure > best || (ntreasure == best && aux.dist < t)){
                best = ntreasure;
                t = aux.dist;
            }
        }
        
        for(int k = 0;k < 4;++k){
            int r = aux.r + dr[k],c = aux.c + dc[k];
            
            if(r >= 0 && r < n && c >= 0 && c < m){
                int d = ed[r][c];
                int r2 = er[r][c],c2 = ec[r][c];
                
                if(r2 != -2 && (M[r2][c2] == '0' || M[r2][c2] == '$')){
                    int to = id[r2][c2];
                    int mask = aux.mask;
                    
                    if(M[r2][c2] == '$') mask |= id2[to];
                    
                    if(dist[to][mask] == -1 || aux.dist + 1 + d < dist[to][mask]){
                        Q.push(node(r2,c2,mask,aux.dist + 1 + d));
                        dist[to][mask] = aux.dist + 1 + d;
                    }
                }
            }
        }
    }
    
    if(best != -1) t += 2 * best;
    return t;
}

int main(){
    while(scanf("%d %d",&n,&m) == 2){
        for(int i = 0;i < n;++i)
            scanf("%s",M[i]);
        
        memset(in,false,sizeof in);
        memset(er,-1,sizeof er);
        int cont = 0,cont2 = 0;
        memset(id,-1,sizeof id);
        memset(id2,0,sizeof id2);
        
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                dfs(i,j);
                
                if(M[i][j] == '0' || M[i][j] == '$'){
                    if(M[i][j] == '$'){
                        id2[cont] = (1 << cont2);
                        ++cont2;
                    }
                    
                    id[i][j] = cont;
                    ++cont;
                }
            }
        }
        
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        --x1; --y1; --x2; --y2;
        
        printf("%d\n",dijkstra());
    }    
    
    return 0;
}
