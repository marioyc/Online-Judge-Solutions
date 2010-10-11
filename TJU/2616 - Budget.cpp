#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

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
    
    int max_flow(int source, int sink){
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
        
        add_edge(sink,source,0,INT_MAX);
        
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
        
        if(f!=sum) return -1;
        
        for(int e = 0;e<E;e += 2){
            cap[e] += low[e];
            flow[e] += low[e];
            flow[e^1] -= low[e];
            cap[e^1] -= low[e];
        }
        
        s = source; t = sink;
        
        last[s] = next[last[s]];
        last[t] = next[last[t]];
        E -= 2;
        
        while(bfs()){
            for(int i = V-1;i>=0;--i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
        
        return f;
    }
}G(2+200+20,200+200*20+20);

int sum_r[200],sum_c[20];
int L[200][20],U[200][20],ans[200][20];

bool solve(int R, int C){
    for(int i = 0;i<R;++i)
        for(int j = 0;j<C;++j)
            if(L[i][j]>U[i][j])
                return false;
    
    G.clear(R+C+2);
    
    for(int i = 0;i<R;++i)
        G.add_edge(0,1+i,0,sum_r[i]);
    
    for(int i = 0;i<C;++i)
        G.add_edge(1+R+i,1+R+C,0,sum_c[i]);
    
    for(int i = 0;i<R;++i)
        for(int j = 0;j<C;++j)
            G.add_edge(1+i,1+R+j,L[i][j],U[i][j]);
    
    int f = G.max_flow(0,1+R+C);
    if(f==-1) return false;
    
    int sum = 0;
    for(int i = 0;i<R;++i) sum += sum_r[i];
    if(f!=sum) return false;
    
    memset(ans,0,sizeof(ans));
    
    int E = G.E;
    
    for(int e = 0,u,v;e<E;e += 2){
        u = G.to[e^1]; v = G.to[e];
        
        if(u>=1 && u<=R && v>=1+R && v<=1+R+C)
            ans[u-1][v-1-R] = G.flow[e];
    }
    
    return true;
}

int main(){
    int T,m,n,SR,SC;
    int c,a,b,x;
    char sym;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %d",&m,&n);
        
        SR = 0;
        
        for(int i = 0;i<m;++i){
            scanf("%d",&sum_r[i]);
            SR += sum_r[i];
        }
        
        SC = 0;
        
        for(int i = 0;i<n;++i){
            scanf("%d",&sum_c[i]);
            SC += sum_c[i];
        }
        
        
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                L[i][j] = 0;
                U[i][j] = min(sum_r[i],sum_c[j]);
            }
        }
        
        scanf("%d",&c);
        
        for(int i = 0;i<c;++i){
            scanf("%d %d %c %d",&a,&b,&sym,&x);
            
            if(a==0){
                if(b==0){
                    for(int i = 0;i<m;++i){
                        for(int j = 0;j<n;++j){
                            if(sym=='<') U[i][j] = min(U[i][j],x-1);
                            else if(sym=='>') L[i][j] = max(L[i][j],x+1);
                            else{
                                U[i][j] = min(U[i][j],x);
                                L[i][j] = max(L[i][j],x);
                            }
                        }
                    }
                }else{
                    --b;
                    for(int i = 0;i<m;++i){
                        if(sym=='<') U[i][b] = min(U[i][b],x-1);
                        else if(sym=='>') L[i][b] = max(L[i][b],x+1);
                        else{
                            U[i][b] = min(U[i][b],x);
                            L[i][b] = max(L[i][b],x);
                        }
                    }
                }
            }else if(b==0){
                --a;
                for(int i = 0;i<n;++i){
                    if(sym=='<') U[a][i] = min(U[a][i],x-1);
                    else if(sym=='>') L[a][i] = max(L[a][i],x+1);
                    else{
                        U[a][i] = min(U[a][i],x);
                        L[a][i] = max(L[a][i],x);
                    }
                }
            }else{
                --a; --b;
                
                if(sym=='<') U[a][b] = min(U[a][b],x-1);
                else if(sym=='>') L[a][b] = max(L[a][b],x+1);
                else{
                    U[a][b] = min(U[a][b],x);
                    L[a][b] = max(L[a][b],x);
                }
            }
        }
        
        if(tc>1) printf("\n");
        
        if(SR==SC && solve(m,n)){
            for(int i = 0;i<m;++i){
                printf("%d",ans[i][0]);
                
                for(int j = 1;j<n;++j)
                    printf(" %d",ans[i][j]);
                
                printf("\n");
            }
        }else printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
