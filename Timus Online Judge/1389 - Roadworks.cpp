#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V1 100000
#define MAX_V2 100000
#define MAX_E 100000

int V1,V2,left[MAX_V2],right[MAX_V1];
int E,to[MAX_E],next_e[MAX_E],last[MAX_V1];

void hopcroft_karp_init(int v1, int v2){
    V1 = v1; V2 = v2; E = 0;
    memset(last,-1,sizeof(last));
}

void hopcroft_karp_add_edge(int u, int v){
    to[E] = v; next_e[E] = last[u]; last[u] = E++;
}

bool visited[MAX_V1];

bool hopcroft_karp_dfs(int u){
    if(visited[u]) return false;
    visited[u] = true;
    
    for(int e = last[u],v;e!=-1;e = next_e[e]){
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

int N,M;
bool inV1[MAX_V1];
vector<int> L[MAX_V1];

int main(){
	scanf("%d %d",&N,&M);
    
    for(int i = 0,u,v;i<M;++i){        
        scanf("%d %d",&u,&v);
        --u; --v;
        
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(visited,false,sizeof(visited));
    memset(inV1,false,sizeof(inV1));
    
    for(int i = 0;i<N;++i){
        if(!visited[i]){
            queue<int> Q;
            Q.push(i);
            visited[i] = true;
            inV1[i] = true;
            
            while(!Q.empty()){
                int aux = Q.front();
                Q.pop();
                
                for(int j = L[aux].size()-1;j>=0;--j){
                    int v = L[aux][j];
                    
                    if(!visited[v]){
                        Q.push(v);
                        visited[v] = true;
                        inV1[v] = !inV1[aux];
                    }
                }
            }
        }
    }
		
    hopcroft_karp_init(N,N);
    
    for(int i = 0;i<N;++i){
        if(inV1[i]){
            for(int j = L[i].size()-1;j>=0;--j){
                int v = L[i][j];
                if(!inV1[v]) hopcroft_karp_add_edge(i,v);
            }
        }
    }
		
    printf("%d\n",hopcroft_karp_match());
	
	for(int i = 0;i<N;++i)
	    if(right[i]!=-1)
	        printf("%d %d\n",i+1,right[i]+1);
	
	return 0;
}
