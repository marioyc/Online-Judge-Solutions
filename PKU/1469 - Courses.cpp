#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t;
    int *cap,*to,*next,*last;
    bool *visited;
    
    flow_graph(int V, int MAX_E){
        MAX_V = V;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], visited = new bool[MAX_V];
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
    
    int dfs(int v, int f){
        if(v==t || f<=0) return f;
        if(visited[v]) return 0;
        visited[v] = true;
        
        for(int e=last[v];e!=-1;e=next[e]){
            int ret = dfs(to[e],min(f,cap[e]));
            
            if(ret>0){
                cap[e] -= ret;
                cap[e^1] += ret;
                return ret;
            }
        }
        
        return 0;
    }
    
    int max_flow(int source, int sink){
        s = source, t = sink;
        int f = 0,x;
        
        while(true){
            fill(visited,visited+MAX_V,false);
            x = dfs(s,INT_MAX);
            if(x==0) break;
            f += x;
        }
        
        return f;
    }
};

int main(){
    int T,N,P,nStudents,student;
    scanf("%d",&T);
    
    flow_graph G(100+300+2,100+100*300+300);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&P,&N);
        
        G.clear();
        
        for(int i=0;i<P;++i){
            scanf("%d",&nStudents);
            
            for(int j=0;j<nStudents;++j){
                scanf("%d",&student);
                G.add_edge(1+i,P+student,1);
            }
        }
        
        for(int i=0;i<P;++i) G.add_edge(0,1+i,1);
        for(int i=0;i<N;++i) G.add_edge(1+P+i,1+P+N,1);
        
        printf("%s\n",G.max_flow(0,1+P+N)==P? "YES":"NO");
    }
    
    return 0;
}
