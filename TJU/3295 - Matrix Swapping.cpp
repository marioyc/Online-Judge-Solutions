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
    int N,pos[100],col[100];
    int R1[100],R2[100],cont;
    
    while(scanf("%d",&N)==1){
        hopcroft_karp_init(N,N);
        
        for(int i = 0,x;i<N;++i) for(int j = 0;j<N;++j){
            scanf("%d",&x);
            if(x==1) hopcroft_karp_add_edge(i,j);
        }
        
        if(hopcroft_karp_match()!=N) puts("-1");
        else{
            for(int r = 0,c;r<N;++r){
                c = right[r];
                pos[c] = r;
                col[r] = c;
            }
            
            cont = 0;
            
            for(int r = 0,r2;r<N;++r){
                if(col[r]!=r){
                    r2 = pos[r];
                    col[r2] = col[r];
                    pos[col[r]] = r2;
                    col[r] = r;
                    pos[r] = r;
                    
                    R1[cont] = r;
                    R2[cont] = r2;
                    
                    ++cont;
                }
            }
            
            printf("%d\n",cont);
            for(int i = 0;i<cont;++i) printf("R %d %d\n",1+R1[i],1+R2[i]);
        }
    }
    
    return 0;
}
