#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=10050,MAXM=100500,MAXE=2*MAXN;

int N,E;
int to[MAXE],next[MAXE],last[MAXN],val[MAXN];
int to2[MAXE],next2[MAXE],last2[MAXN],val2[MAXN];

int parent[MAXN];

int Find(const int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

int dfsNum[MAXN],num,low[MAXN];

void dfs(const int u, const int p){
    dfsNum[u]=low[u]=num++;
    
    for(int e=last[u];e!=-1;e=next[e]){
        if(to[e]!=p){
            if(dfsNum[to[e]]==-1) dfs(to[e],u);
            low[u]<?=low[to[e]];
        }
    }
    
    if(low[u]<dfsNum[u] && p!=-1) parent[u]=Find(p);
}

int ans;

int solve(const int u, const int p){
    int sum=val2[u],aux;
    
    for(int e=last2[u];e!=-1;e=next2[e]){
        if(to2[e]!=p){
            aux=solve(to2[e],u);
            ans>?=aux;
            sum+=aux;
        }
    }
    
    return sum;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int u,v,ne;
    
    while(1){
        scanf("%d %d",&N,&E);
        if(N==0) break;
        
        memset(last,-1,sizeof(last));
        ne=0;
        
        for(int i=0;i<E;i++){
            scanf("%d %d",&u,&v);
            u--, v--;
            to[ne]=v, next[ne]=last[u], last[u]=ne++;
            to[ne]=u, next[ne]=last[v], last[v]=ne++;
        }
        
        for(int i=0;i<N;i++) scanf("%d",&val[i]);
        for(int i=0;i<N;i++) parent[i]=i;
        
        num=0;
        memset(dfsNum,-1,sizeof(dfsNum));
        dfs(0,-1);
        
        memset(last2,-1,sizeof(last2));
        memset(val2,0,sizeof(val2));
        ne=0;
        
        for(int i=0;i<N;i++){
            u=Find(i);
            val2[u]+=val[i];
            for(int e=last[i];e!=-1;e=next[e]){
                v=Find(to[e]);
                if(u==v) continue;
                to2[ne]=v, next2[ne]=last2[u], last2[u]=ne++;
            }
        }
        
        ans=-10000001;
        solve(0,-1);
        
        if(ans==-10000001) printf("No apple\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
