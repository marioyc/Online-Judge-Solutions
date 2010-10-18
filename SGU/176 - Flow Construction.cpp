#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_OUT = (100-2)*100000;

struct flow_graph{
    int V,E,s,t;
    int *flow,*low,*cap,*to,*next,*last,*delta;
    int *dist,*q,*now,head,tail;
    
    flow_graph(){}
    
    flow_graph(int V, int E){
        (*this).V = V; (*this).E = 0;
        int TE = 2*(E+V+1);
        flow = new int[TE]; low = new int[TE]; cap = new int[TE];
        to = new int[TE]; next = new int[TE];
        last = new int[V+2]; delta = new int[V];
        dist = new int[V+2]; q = new int[V+2]; now = new int[V+2];
    }
    
    void clear(int V){
        (*this).V = V; (*this).E = 0;
        fill(last,last+V,-1);
    }
    
    void add_edge(int a, int b, int l, int u){
        to[E] = b; low[E] = l; cap[E] = u; flow[E] = 0;
        next[E] = last[a]; last[a] = E++;
        
        to[E] = a; low[E] = 0; cap[E] = 0; flow[E] = 0;
        next[E] = last[b]; last[b] = E++;
    }
    
    bool bfs(){
        fill(dist,dist+V+2,-1);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>flow[e^1] && dist[to[e]]==-1){
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
            if(cap[e]>flow[e] && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]-flow[e]));
				
                if(ret>0){
                    flow[e] += ret;
                    flow[e^1] -= ret;
                    return ret;
                }
            }
        }
		
        return 0;
    }
    
    bool find_circulation(){
        fill(delta,delta+V,0);
        
        for(int e = 0;e<E;e += 2){
            delta[to[e^1]] -= low[e];
            delta[to[e]] += low[e];
            cap[e] -= low[e];
        }
        
        last[V] = last[V+1] = -1;
        int sum = 0;
        
        for(int i = 0;i<V;++i){
            if(delta[i]>0){
                add_edge(V,i,0,delta[i]);
                sum += delta[i];
            }
            if(delta[i]<0) add_edge(i,V+1,0,-delta[i]);
        }
        
        s = V; t = V+1;
        int f = 0,df;
        
        fill(flow,flow+E,0);
        
        while(bfs()){
            for(int i = V+1;i>=0;--i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
        
        if(f!=sum) return false;
        
        for(int e = 0;e<E;e += 2){
            cap[e] += low[e];
            flow[e] += low[e];
            flow[e^1] -= low[e];
            cap[e^1] -= low[e];
        }
        
        return true;
    }
}G(100,4950);

int N,M,U[4950],V[4950],low[4950],cap[4950];

bool solve(int max_allowed, bool print){
    G.clear(N);
    
    for(int i = 0;i<M;++i)
        G.add_edge(U[i],V[i],low[i],cap[i]);
    
    G.add_edge(N-1,0,0,max_allowed);
    
    bool f = G.find_circulation();
    
    if(print){
        printf("%d\n",max_allowed);
        
        for(int i = 0;i<M;++i)
            printf("%d%c",G.flow[2*i],i==M-1? '\n' : ' ');
    }
    
    return f;
}

int main(){
    scanf("%d %d",&N,&M);
    
    for(int i = 0,c;i<M;++i){
        scanf("%d %d %d %d",&U[i],&V[i],&cap[i],&c);
        --U[i]; --V[i];
        low[i] = (c==1? cap[i] : 0);
    }
    
    bool f = solve(MAX_OUT, false);
    
    if(!solve(MAX_OUT, false)) printf("Impossible\n");
    else{
        int lo = 0,hi = MAX_OUT,mi;
        
        while(lo!=hi){
            mi = (lo+hi)/2;
            
            if(!solve(mi, false)) lo = mi+1;
            else hi = mi;
        }
        
        solve(lo, true);
    }
    
    return 0;
}
