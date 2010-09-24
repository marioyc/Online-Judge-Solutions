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

#define NQUEUES 10
node Q[NQUEUES][30000],aux;
int Q_size[NQUEUES],current_queue;

int R,C;
int cost[999][999],dist[999][999];
bool done[999][999];

int total_nodes;

void enqueue(int r, int c, int w){
    if(w>=dist[r][c]) return;
    dist[r][c] = w;
    
    int sz = Q_size[w%10];
    Q[w%10][sz].r = r;
    Q[w%10][sz].c = c;
    ++Q_size[w%10];
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

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

void shortest_path(int sr, int sc, int er, int ec){
    total_nodes = 0;
    for(int i=0;i<NQUEUES;++i) Q_size[i] = 0;
    current_queue = 0;
    
    int r,c,r2,c2;
    enqueue(sr,sc,cost[sr][sc]);
    
    while(dequeue(r,c)){
        if(done[r][c]) continue;
        done[r][c] = true;
        
        if(r==er && c==ec)  return;
        
        for(int k=0;k<4;++k){
            r2 = r+dr[k]; c2 = c+dc[k];
            if(r2<0 || r2>=R || c2<0 || c2>=C || done[r2][c2]) continue;
            enqueue(r2,c2,dist[r][c]+cost[r2][c2]);
        }
    }
    
    return;
}

int main(){
    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                scanf("%d",&cost[i][j]);
        
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                dist[i][j] = INT_MAX;
        
        memset(done,false,sizeof(done));
        
        shortest_path(0,0,R-1,C-1);
        
        printf("%d\n",dist[R-1][C-1]);
    }
}
