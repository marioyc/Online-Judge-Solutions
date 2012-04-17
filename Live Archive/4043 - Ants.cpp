#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_V 100
double eps = 1e-7;

int V;
double cost[MAX_V][MAX_V];
double lx[MAX_V],ly[MAX_V];
int max_match,xy[MAX_V],yx[MAX_V],prev[MAX_V];
bool S[MAX_V],T[MAX_V];
double slack[MAX_V];
int slackx[MAX_V];
int q[MAX_V],head,tail;

void init_labels(){
    for(int i = 0;i < V;++i)
        lx[i] = ly[i] = 0;
  
    for(int x = 0;x<V;++x)
        for(int y = 0;y<V;++y)
            lx[x] = max(lx[x],cost[x][y]);
}

void update_labels(){
    int x,y;
    double delta = 1e13;
  
    for(y = 0;y<V;++y) if(!T[y]) delta = min(delta,slack[y]);
    for(x = 0;x<V;++x) if(S[x]) lx[x] -= delta;
    for(y = 0;y<V;++y) if(T[y]) ly[y] += delta;
    for(y = 0;y<V;++y) if(!T[y]) slack[y] -= delta;
}

void add_to_tree(int x, int prevx){
    S[x] = true;
    prev[x] = prevx;
  
    for(int y = 0;y<V;++y){
        if(lx[x]+ly[y]-cost[x][y]<slack[y] + eps){
            slack[y] = lx[x]+ly[y]-cost[x][y];
            slackx[y] = x;
        }
    }
}

void augment(){
    int x,y,root;
    head = tail = 0;
    memset(S,false,sizeof(S));
    memset(T,false,sizeof(T));
    memset(prev,-1,sizeof(prev));
    
    for(x = 0;x<V;++x){
        if(xy[x]==-1){
            q[tail++] = root = x;
            prev[root] = -2;
            S[root] = true;
            break;
        }
    }
  
    for(y = 0;y<V;++y){
        slack[y] = lx[root]+ly[y]-cost[root][y];
        slackx[y] = root;
    }
  
    while(true){
        while(head<tail){
            x = q[head++];
      
            for(y = 0;y<V;++y){
                if(abs(cost[x][y]-lx[x]-ly[y]) < eps && !T[y]){
                    if(yx[y]==-1) break;
          
                    T[y] = true;
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],x);
                }
            }
      
            if(y<V) break;
        }
    
        if(y<V) break;
    
        update_labels();
        head = tail = 0;
    
        for(y = 0;y<V;++y){
            if(!T[y] && abs(slack[y]) < eps){
                if(yx[y]==-1){
                    x = slackx[y];
                    break;
                }
        
                T[y] = true;
        
                if(!S[yx[y]]){
                    q[tail++] = yx[y];
                    add_to_tree(yx[y],slackx[y]);
                }
            }
        }
    
        if(y<V) break;
    }
  
    ++max_match;
  
    for(int cx = x,cy = y,ty;cx!=-2;cx = prev[cx],cy = ty){
        ty = xy[cx];
        yx[cy] = cx;
        xy[cx] = cy;
    }
}

void hungarian(){
    max_match = 0;
    memset(xy,-1,sizeof(xy));
    memset(yx,-1,sizeof(yx));
  
    init_labels();
    for(int i = 0;i<V;++i) augment();
}

int main(){
    int n,x1[100],y1[100],x2[100],y2[100];
    bool first = true;
    
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i)
            scanf("%d %d",&x1[i],&y1[i]);
        
        for(int i = 0;i < n;++i)
            scanf("%d %d",&x2[i],&y2[i]);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                cost[i][j] = -sqrt((x1[i] - x2[j]) * (x1[i] - x2[j]) + (y1[i] - y2[j]) * (y1[i] - y2[j]));
        
        V = n;
        hungarian();
        
        if(!first) printf("\n");
        first = false;
        
        for(int i = 0;i < n;++i)
            printf("%d\n",1 + xy[i]);
    }
    
    return 0;
}
