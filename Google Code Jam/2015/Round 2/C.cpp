#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

struct flow_graph{
    static const int MAX_V = 9000;
    static const int MAX_E = 20000;

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

    int max_flow(int source, int sink, int V){
        s = source; t = sink;
        int f = 0,df;

        while(bfs()){
            for(int i = 0;i < V;++i) now[i] = last[i];

            while(true){
                df = dfs(s,INT_MAX);
                if(df == 0) break;
                f += df;
            }
        }

        return f;
    }
}G;

map<string, int> id;

int main(){
    int T,N;
    int V1 = 2 * (1000 * 2 + 10 * 198);
    int V = V1 + 200 + 2;
    string line,w;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        getline(cin,line);
        int cont = 0;
        id.clear();
        G.clear();

        for(int i = 0;i < N;++i){
            getline(cin, line);
            istringstream is(line);

            while(is >> w){
                if(id.find(w) == id.end()){
                    id[w] = cont;
                    G.add_edge(2 * cont,2 * cont + 1,1);
                    ++cont;
                }

                int cur = id[w];

                if(i == 0){
                    G.add_edge(V - 2,2 * cur,5000);
                }else if(i == 1){
                    G.add_edge(2 * cur + 1,V - 1,5000);
                }else{
                    G.add_edge(V1 + i,2 * cur,5000);
                    G.add_edge(2 * cur + 1,V1 + i,5000);
                }
            }
        }

        cout << "Case #" << tc << ": " << G.max_flow(V - 2,V - 1,V) << '\n';
    }

    return 0;
}
