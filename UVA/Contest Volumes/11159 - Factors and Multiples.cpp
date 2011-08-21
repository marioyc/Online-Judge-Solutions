#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_V1 100
#define MAX_V2 100
#define MAX_E 10000

int V1,V2,left[MAX_V2],right[MAX_V1];
int E,to[MAX_E],next[MAX_E],last[MAX_V1];

void hopcroft_karp_init(int v1, int v2){
    V1 = v1; V2 = v2; E = 0;
    memset(last,-1,sizeof(last));
}

void hopcroft_karp_add_edge(int u, int v){
    to[E] = v; next[E] = last[u]; last[u] = E++;
}

bool visited[MAX_V1];

bool hopcroft_karp_dfs(int u){
    if(visited[u]) return false;
    visited[u] = true;
    
    for(int e = last[u],v;e!=-1;e = next[e]){
        v = to[e];
        
        if(left[v]==-1 || hopcroft_karp_dfs(left[v])){
            right[u] = v;
            left[v] = u;
            return true;
        }
    }
    
    return false;
}

int hopcroft_karp_match(){
    memset(left,-1,sizeof(left));
    memset(right,-1,sizeof(right));
    bool change = true;
    
    while(change){
        change = false;
        memset(visited,false,sizeof(visited));
        
        for(int i = 0;i<V1;++i)
            if(right[i]==-1)
                change |= hopcroft_karp_dfs(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i<V1;++i)
        if(right[i]!=-1) ++ret;
    
    return ret;
}

int main(){
    int T,n,m;
    int A[100],B[100];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&A[i]);
        
        scanf("%d",&m);
        
        for(int i = 0;i < m;++i)
            scanf("%d",&B[i]);
        
        hopcroft_karp_init(n,m);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if((A[i] != 0 && B[j] % A[i] == 0) || B[j] == 0)
                    hopcroft_karp_add_edge(i,j);
        
        printf("Case %d: %d\n",tc,hopcroft_karp_match());
    }
    
    return 0;
}
