#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t;
    int *cap,*to,*next,*last;
    bool *visited;
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], visited = new bool[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
    
    int dfs(int v, int f){
        if(v==t || f<=0) return f;
        if(visited[v]) return 0;
        visited[v] = true;
        for(int e=last[v];e!=-1;e=next[e]){
            int ret = dfs(to[e],min(f,cap[e]));
            if(ret>0){
                cap[e] -= ret;
                cap[e^1] += ret;
                return ret;
            }
        }
        return 0;
   }
   
   int max_flow(int source, int sink){
       s = source, t = sink;
       int f = 0,x;
       while(true){
           fill(visited,visited+MAX_V,false);
           x = dfs(s,INT_MAX);
           if(x==0) break;
           f += x;
       }
       return f;
   }
};

const int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};

int main(){
    int T,C,R,w[20][20],total;
    scanf("%d",&T);
    
    flow_graph G(2+20*20,2*20+4*20*20);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&C,&R);
        
        total = 0;
        
        for(int i=0;i<R;++i) for(int j=0;j<C;++j){
            scanf("%d",&w[i][j]);
            total += w[i][j];
        }
        
        G.clear();
        
        for(int r=0;r<R;++r) for(int c=r%2;c<C;c+=2)
            G.add_edge(0,1+r*C+c,w[r][c]);
        
        for(int r=0;r<R;++r) for(int c=(r+1)%2;c<C;c+=2)
            G.add_edge(1+r*C+c,R*C+1,w[r][c]);
        
        for(int r=0;r<R;++r) for(int c=r%2;c<C;c+=2){
            for(int k=0;k<4;++k){
                int r2 = r+dr[k], c2 = c+dc[k];
                if(r2>=0 && r2<R && c2>=0 && c2<C){
                    G.add_edge(1+r*C+c,1+r2*C+c2,total+1);
                }
            }
        }
        
        printf("Case %d: %d\n",tc,total-G.max_flow(0,R*C+1));
    }
    
    return 0;
}
