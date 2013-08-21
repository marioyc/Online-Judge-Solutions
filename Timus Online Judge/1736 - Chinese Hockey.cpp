#include <iostream>
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
	
    long long max_flow(int source, int sink){
        s = source; t = sink;
        long long f = 0,df;
		
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
}G(1 + 200 + 200 * 199 / 2 + 1,200 + 200 * 199 + 200 * 199 / 2);

int rival[200][200 * 199 / 2];
int M[200][200];

int main(){
    int n;
    
    cin >> n;
    
    int T = 1 + n + n * (n - 1) / 2;
    int sc[200];
    
    for(int i = 0;i < n;++i) cin >> sc[i];
    
    for(int i = 0;i < n;++i)
        G.add_edge(0,1 + i,sc[i]);
    
    for(int i = 0,cont = 0;i < n;++i){
        for(int j = i + 1;j < n;++j){
            G.add_edge(1 + i,1 + n + cont,3);
            G.add_edge(1 + j,1 + n + cont,3);
            G.add_edge(1 + n + cont,T,3);
            
            rival[i][cont] = j;
            rival[j][cont] = i;
            
            cont++;
        }
    }
    
    if(G.max_flow(0,T) != 3 * n * (n - 1) / 2) cout << "INCORRECT" << endl;
    else{
        cout << "CORRECT" << endl;
        
        for(int e = 0;e < G.E;e += 2){
            int u = G.to[e ^ 1] - 1,v = G.to[e] - 1 - n;
            
            if(u >= 0 && u < n && v >= 0 && v < n * (n - 1) / 2){
                int x = rival[u][v];
                M[u][x] = 3 - G.cap[e];
            }
        }
        
        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                if(M[i][j] == 0) cout << i + 1 << " < " << j + 1 << endl;
                if(M[i][j] == 1) cout << i + 1 << " <= " << j + 1 << endl;
                if(M[i][j] == 2) cout << i + 1 << " >= " << j + 1 << endl;
                if(M[i][j] == 3) cout << i + 1 << " > " << j + 1 << endl;
            }
        }
    }
    
    return 0;
}
