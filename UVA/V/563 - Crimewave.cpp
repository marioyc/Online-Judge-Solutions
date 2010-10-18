#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
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
	
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
	
    int dfs(int v, int f){
        if(v==t) return f;
		
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
				
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
		
        return 0;
    }
	
    int max_flow(int source, int sink){
        s = source; t = sink;
        int f = 0,df;
		
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
		
        return f;
    }
}G(2*50*50+2,50*50+2*50*50*4+50*50+50*4);

int main(){
    int T,W,H,B,x,y,x2,y2;
    int cont[50][50];
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&W,&H,&B);
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<B;++i){
            scanf("%d %d",&x,&y);
            ++cont[x-1][y-1];
        }
        
        G.clear();
        int t = 1+2*(H*W),V = t;
        
        for(x = 0;x<W;++x) for(y = 0;y<H;++y){
            int u = x*H+y;
            
            G.add_edge(1+2*u,1+2*u+1,1);
            
            if(x==0 || x==W-1 || y==0 || y==H-1)
                G.add_edge(1+2*u+1,t,1);
            
            if(cont[x][y]>0)
                G.add_edge(0,1+2*u,cont[x][y]);
            
            for(int k = 0;k<4;++k){
                x2 = x+dx[k]; y2 = y+dy[k];
                
                if(x2>=0 && x2<W && y2>=0 && y2<H){
                    int v = x2*H+y2;
                    
                    G.add_edge(1+2*u+1,1+2*v,1);
                }
            }
        }
        
        printf("%spossible\n",G.max_flow(0,t)==B? "" : "not ");
    }
    
    return 0;
}
