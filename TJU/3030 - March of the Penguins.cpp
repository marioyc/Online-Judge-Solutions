#include <cstdio>
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
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
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
}G(1+2*100,100+100*99+100);

int main(){
    int T,N,x[100],y[100],n[100],m[100],total;
    double D;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %lf",&N,&D);
        
        total = 0;
        
        for(int i = 0;i<N;++i){
            scanf("%d %d %d %d",&x[i],&y[i],&n[i],&m[i]);
            total += n[i];
        }
        
        bool found = false;
        
        for(int k = 0;k<N;++k){
            G.clear();
            
            for(int i = 0;i<N;++i) G.add_edge(0,2*i+1,n[i]);
            for(int i = 0;i<N;++i) G.add_edge(2*i+1,2*i+2,m[i]);
            
            for(int i = 0;i<N;++i) for(int j = i+1;j<N;++j){
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=D*D){
                    G.add_edge(2*i+2,2*j+1,total);
                    G.add_edge(2*j+2,2*i+1,total);
                }
            }
            
            if(G.max_flow(0,2*k+1)==total){
                if(found) putchar(' ');
                found = true;
                printf("%d",k);
            }
        }
        
        if(!found) printf("-1\n");
        else putchar('\n');
    }
    
    return 0;
}
