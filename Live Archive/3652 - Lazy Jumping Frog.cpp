#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

struct node{
    int r,c;
    
    node(){}
    
    node(int _r, int _c){
        r = _r; c = _c;
    }
};

#define NQUEUES 8
node Q[NQUEUES][5000],aux;
int Q_size[NQUEUES],current_queue;

int R,C;
int dist[1000][1000];
bool done[1000][1000];

const int energy[][5] = {
    {7,6,5,6,7},
    {6,3,2,3,6},
    {5,2,0,2,5},
    {6,3,2,3,6},
    {7,6,5,6,7}
};

int total_nodes;

void enqueue(int r, int c, int w){
    if(r<0 || r>=R || c<0 || c>=C || done[r][c]) return;
    if(w>=dist[r][c]) return;
    dist[r][c] = w;
    
    int sz = Q_size[w&7];
    Q[w&7][sz].r = r;
    Q[w&7][sz].c = c;
    ++Q_size[w&7];
    ++total_nodes;
}

bool dequeue(int &r, int &c){
    if(total_nodes==0) return false;
    
    while(Q_size[current_queue]==0){
        ++current_queue;
        if(current_queue==NQUEUES) current_queue = 0;
    }
    
    --Q_size[current_queue];
    aux = Q[current_queue][Q_size[current_queue]];
    r = aux.r; c = aux.c;
    --total_nodes;
    
    return true;
}

void shortest_path(int &sr, int &sc, int &er, int &ec){
    total_nodes = 0;
    for(int i=0;i<NQUEUES;++i) Q_size[i] = 0;
    current_queue = 0;
    
    int r,c;
    enqueue(sr,sc,0);
    
    while(dequeue(r,c)){
        if(done[r][c]) continue;
        done[r][c] = true;
        
        if(r==er && c==ec)  return;
        
        for(int dr=-2;dr<=2;++dr)
            for(int dc=-2;dc<=2;++dc)
                enqueue(r+dr,c+dc,dist[r][c]+energy[dr+2][dc+2]);
    }
    
    return;
}

int main(){
    int sr,sc,er,ec,W,r1,c1,r2,c2;    
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R==0) break;
        
        scanf("%d %d %d %d %d",&sr,&sc,&er,&ec,&W);
        --sr; --sc; --er; --ec;
        
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                dist[i][j] = INT_MAX;
        
        memset(done,false,sizeof(done));
        
        while(W--){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            --r1; --c1; --r2; --c2;
            for(int i=r1;i<=r2;++i)
                for(int j=c1;j<=c2;++j)
                    done[i][j] = true;
        }
        
        shortest_path(sr,sc,er,ec);
        if(dist[er][ec]==INT_MAX) printf("impossible\n");
        else printf("%d\n",dist[er][ec]);
    }
}
