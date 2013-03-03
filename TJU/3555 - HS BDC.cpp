#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1000

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
}G(1 + 26 + MAXN + 1,26 + 2*MAXN + MAXN);

int parent[26];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int ne,u[MAXN],v[MAXN],rev[MAXN];
int cap[26];

int solve(){
    G.clear();
    
    for(int i = 0;i < 26;++i){
        if(cap[i] < 0) return -1;
        if(cap[i] > 0) G.add_edge(0,1 + i,cap[i]);
    }
    
    for(int i = 0;i < ne;++i){
        G.add_edge(u[i],27 + i,1);
        G.add_edge(v[i],27 + i,1);
        G.add_edge(27 + i,27 + ne,1);
    }
    
    return G.max_flow(0,27 + ne);
}

int main(){
    int T,N;
    bool seen[26];
    int in[26],out[26],all[26];
    vector<int> odd;
    char s[21];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        ne = 0;
        
        for(int i = 0;i < 26;++i)
            parent[i] = i;
        
        memset(seen,false,sizeof seen);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        memset(all,0,sizeof all);
        
        for(int i = 0;i < N;++i){
            scanf("%s %d",s,&rev[ne]);
            int L = strlen(s);
            
            if(s[0] != s[L - 1]){
                u[ne] = s[0] - 'a';
                v[ne] = s[L - 1] - 'a';
                Union(u[ne],v[ne]);
                seen[ u[ne] ] = seen[ v[ne] ] = true;
                
                ++all[ u[ne] ]; ++all[ v[ne] ];
                
                if(rev[ne] == 0){
                    ++out[ u[ne] ];
                    ++in[ v[ne] ];
                }else ++ne;
            }
        }
        
        bool connected = true;
        int root;
        
        for(int i = 0;i < 26;++i)
            if(seen[i]) root = i;
        
        for(int i = 0;i < 26;++i)
            if(seen[i] && Find(i) != Find(root))
                connected = false;
        
        odd.clear();
        
        for(int i = 0;i < 26;++i)
            if(all[i] & 1)
                odd.push_back(i);
        
        if(!connected || odd.size() > 2) printf("Case %d: Poor boy!\n",tc);
        else{
            bool found = true;
            
            for(int i = 0;i < 26;++i)
                cap[i] = all[i] / 2 - in[i];
            
            if(odd.size() == 0){
                int ret = solve();
                if(ret == ne) found = true;
            }else{
                ++cap[ odd[0] ];
                int ret = solve();
                if(ret == ne) found = true;
                
                if(!found){
                    --cap[ odd[0] ];
                    ++cap[ odd[1] ];
                    int ret = solve();
                    if(ret == ne) found = true;
                }
            }
            
            if(found) printf("Case %d: Well done!\n",tc);
            else printf("Case %d: Poor boy!\n",tc);
        }
    }
    
    return 0;
}
