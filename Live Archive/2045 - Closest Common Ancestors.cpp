#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define LOG2_MAXN 16

// NOTA : memset(parent,-1,sizeof(parent));
int N,parent[MAX_N],L[MAX_N];
int P[MAX_N][LOG2_MAXN];

int get_level(int u){
    if(L[u]!=-1) return L[u];
    else if(parent[u]==-1) return 0;
    return 1+get_level(parent[u]);
}

void init(){
	memset(L,-1,sizeof(L));
	for(int i = 0;i<N;++i) L[i] = get_level(i);
	
	memset(P,-1,sizeof(P));
	
	for(int i = 0;i<N;++i) P[i][0] = parent[i];
	
	for(int j = 1;(1<<j)<N;++j)
	    for(int i = 0;i<N;++i)
		    if(P[i][j-1]!=-1)
			    P[i][j] = P[P[i][j-1]][j-1];
}

int LCA(int p, int q){
    if(L[p]<L[q]) swap(p,q);
    
    int log = 1;
    while((1<<log)<=L[p]) ++log;
    --log;
    
    for(int i = log;i>=0;--i)
        if(L[p]-(1<<i)>=L[q])
            p = P[p][i];
    
    if(p==q) return p;
    
    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    
    return parent[p];
}

int main(){
    int u,v,m,Q,ans[MAX_N];
    
    while(scanf("%d",&N)==1){
        memset(parent,-1,sizeof(parent));
        
        for(int i = 0;i<N;++i){
            scanf("%d:(%d)",&u,&m); --u;
            
            for(int j = 0;j<m;++j){
                scanf("%d",&v); --v;
                parent[v] = u;
            }
        }
        
        init();
        memset(ans,0,sizeof(ans));
        scanf("%d\n",&Q);
        
        for(int q = 0;q<Q;++q){
            scanf("%*[\r\n ]");
            scanf("(%d %d)",&u,&v);
            --u; --v;
            ++ans[LCA(u,v)];
        }
        
        for(int i = 0;i<N;++i)
            if(ans[i]!=0) printf("%d:%d\n",i+1,ans[i]);
    }
    
    return 0;
}
