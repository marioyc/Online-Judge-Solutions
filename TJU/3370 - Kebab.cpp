#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 200

struct flow_graph{
    static const int MAX_V = 3 * MAXN + 2;
    static const int MAX_E = MAXN + 2 * MAXN * MAXN + 2 * MAXN;
    
    int E,s,t,head,tail;
    int cap[2 * MAX_E],to[2 * MAX_E],next[2 * MAX_E],last[MAX_V],dist[MAX_V],q[MAX_V],now[MAX_V];
    
    flow_graph(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void clear(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }
	
    bool bfs(){
        memset(dist,-1,sizeof dist);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head < tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e != -1;e = next[e]){
                if(cap[e^1] > 0 && dist[to[e]] == -1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s] != -1;
    }
	
    int dfs(int v, int f){
        if(v == t) return f;
		
        for(int &e = now[v];e != -1;e = next[e]){
            if(cap[e] > 0 && dist[to[e]] == dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
				
                if(ret > 0){
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
            for(int i = 0;i <= sink;++i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df == 0) break;
                f += df;
            }
        }
		
        return f;
    }
}G;

int main(){
    int N,M,s[MAXN],e[MAXN];
    int a[2 * MAXN + 1],na,want;
    
    while(scanf("%d %d",&N,&M) == 2){
        na = 0;
        a[na++] = 0;
        G.clear();
        want = 0;
        
        for(int i = 0,n,t;i < N;++i){
            scanf("%d %d %d %d",&s[i],&n,&e[i],&t);
            G.add_edge(0,1 + i,n * t);
            want += n * t;
            a[na++] = s[i];
            a[na++] = e[i];
        }
        
        sort(a,a + na);
        na = unique(a,a + na) - a;
        --na;
        
        for(int i = 0;i < na;++i){
            G.add_edge(1 + N + i,1 + N + na,(a[i + 1] - a[i]) * M);
            
            for(int j = 0;j < N;++j)
                if(a[i] >= s[j] && a[i + 1] <= e[j])
                    G.add_edge(1 + j,1 + N + i,1000000);
        }
        
        if(G.max_flow(0,1 + N + na) == want) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
