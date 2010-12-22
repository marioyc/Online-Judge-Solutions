#include <cstdio>
#include <vector>

using namespace std;

vector<int> L[10000];
int child[10000],parent[10000];

void dfs(int cur, int prev){
    child[cur] = 1;
    
    for(int i = L[cur].size()-1;i>=0;--i){
        int nxt = L[cur][i];
        
        if(nxt!=prev){
            dfs(nxt,cur);
            child[cur] += child[nxt];
            parent[nxt] = cur;
        }
    }
}

int main(){
    int T,n,u[9999],v[9999],w[9999];
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i<n;++i) L[i].clear();
        
        for(int i = 0;i+1<n;++i){
            scanf("%d %d %d",&u[i],&v[i],&w[i]);
            L[u[i]].push_back(v[i]);
            L[v[i]].push_back(u[i]);
        }
        
        parent[0] = -2;
        dfs(0,-1);
        
        long long sum = 0;
        
        for(int i = 0;i+1<n;++i)
            if(parent[u[i]]==v[i]) sum += (long long)w[i]*child[u[i]]*(n-child[u[i]]);
            else sum += (long long)w[i]*child[v[i]]*(n-child[v[i]]);
        
        printf("%.6f\n",(double)sum/(n*(n-1)/2));
    }
    
    return 0;
}
