#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30001;
const int MAXD = 5001;

int H[2*MAXN][MAXD],best[2*MAXN];
int id[2*MAXN];
int parent[2*MAXN],rank[2*MAXN];
int aux[MAXD];

void init(int V, int D){
    for(int i = 0;i < V;++i){
        parent[i] = i;
        rank[i] = 0;
        id[i] = i;
        best[i] = 1;
        
        for(int j = 0;j <= D;++j)
            H[i][j] = 1;
    }
}

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int PX = Find(x),PY = Find(y);
    
    if(PX != PY){
        if(rank[PX] < rank[PY]) parent[PX] = PY;
        else{
            if(rank[PX] == rank[PY]) ++rank[PX];
            parent[PY] = PX;
        }
    }
}

int main(){
    int T,N,D;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&N,&D);
        init(N,D);
        
        for(int i = 0,a,b;i < N - 1;i++){
            scanf("%d %d",&a,&b);
            --a; --b;
            
            for(int j = 0;j <= D;++j) H[N + i][j] = N + 1;
            best[N + i] = N + 1;
            
            int PA = id[Find(a)],PB = id[Find(b)];
            
            for(int j = 0;j < D;++j){
                int ha = H[PA][j],hb = best[PB];
                H[N + i][j + 1] = min(H[N + i][j + 1],max(ha,hb + 1));
            }
            
            for(int j = 0;j < D;++j){
                int hb = H[PB][j],ha = best[PA];
                H[N + i][j + 1] = min(H[N + i][j + 1],max(hb,ha + 1));
            }
            
            for(int j = 0;j <= D;++j)
                best[N + i] = min(best[N + i],H[N + i][j]);
            
            Union(a,b);
            id[Find(a)] = N + i;
        }
        
        printf("Case #%d: %d\n",tc,best[2 * N - 2]);
    }
    
    return 0;
}
