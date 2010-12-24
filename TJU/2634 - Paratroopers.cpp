#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *to,*next,*last,*dist,*q,*now;
    double *cap;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new double[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, double uv, double vu = 0){
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
                if(cap[e^1]>1e-7 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
	
    double dfs(int v, double f){
        if(v==t) return f;
		
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>1e-7 && dist[to[e]]==dist[v]-1){
                double ret = dfs(to[e],min(f,cap[e]));
				
                if(ret>1e-7){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
		
        return 0;
    }
	
    double max_flow(int source, int sink){
        s = source; t = sink;
        double f = 0,df;
		
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                df = dfs(s,10);
                if(df<1e-7) break;
                f += df;
            }
        }
		
        return f;
    }
}G(102,600);

int main(){
    int T,R,C,N;
    double x;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&R,&C,&N);
        G.clear();
        
        for(int i = 0;i<R;++i){
            scanf("%lf",&x);
            G.add_edge(0,1+i,log(x));
        }
        
        for(int i = 0;i<C;++i){
            scanf("%lf",&x);
            G.add_edge(1+R+i,1+R+C,log(x));
        }
        
        for(int i = 0,r,c;i<N;++i){
            scanf("%d %d",&r,&c);
            --r; --c;
            G.add_edge(1+r,1+R+c,10);
        }
        
        printf("%.4f\n",exp(G.max_flow(0,1+R+C)));
    }
    
    return 0;
}
