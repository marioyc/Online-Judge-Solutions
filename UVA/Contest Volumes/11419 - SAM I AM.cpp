#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iostream>
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
}G(2002,1000000);

bool visited[2002];

void BFS(){
    memset(visited,false,sizeof(visited));
    
    int Q[2002], head = 0, tail = 0;
    
    visited[0] = true;
    Q[0] = 0; ++tail;
    
    while(head<tail){
        int pos = Q[head];
        ++head;
        
        for(int e = G.last[pos];e!=-1;e = G.next[e]){
            if(G.cap[e]>0){
                int next = G.to[e];
                
                if(!visited[next]){
                    visited[next] = true;
                    Q[tail] = next;
                    ++tail;
                }
            }
        }
    }
    
    return;
}

int main(){
    int R,C,E,r,c;
    
    while(scanf("%d %d %d",&R,&C,&E)==3){
        G.clear();
        
        for(int i = 0;i<R;++i)
            G.add_edge(0,1+i,1);
        
        for(int i = 0;i<C;++i)
            G.add_edge(1+R+i,1+R+C,1);
        
        for(int i = 0;i<E;++i){
            scanf("%d %d",&r,&c);
            G.add_edge(r,R+c,1);
        }
        
        printf("%d",G.max_flow(0,1+R+C));
        BFS();
        
        for(int i = 1;i<=R;++i) if(!visited[i]) printf(" r%d",i);
        for(int i = 1;i<=C;++i) if(visited[R+i]) printf(" c%d",i);
        printf("\n");
    }
    
    return 0;
}
