#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 5005

struct edge{
    int to,w;
    
    edge(){}
    edge(int _to, int _w):
        to(_to),w(_w){}
};

int n,u[MAXN],v[MAXN],w[MAXN];
vector<edge> L[MAXN];
int cont[MAXN];

void dfs(int cur, int p, int &m, long long sum, long long &C){
    C += sum;
    cont[cur] = 1;
    ++m;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i].to;
        
        if(to != p){
            dfs(to,cur,m,sum + L[cur][i].w,C);
            cont[cur] += cont[to];
        }
    }
}

int m;

void dfs2(int cur, int p, int we, long long &sum1, long long &best, long long aux){
    if(aux < best) best = aux;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i].to;
        
        if(to != p)
            dfs2(to,cur,L[cur][i].w,sum1,best,aux + (long long)(m - 2 * cont[to]) * L[cur][i].w);
    }
    
    if(we != -1)
        sum1 += (long long)we * cont[cur] * (m - cont[cur]);
}

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n - 1;++i){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        L[u[i]].push_back(edge(v[i],w[i]));
        L[v[i]].push_back(edge(u[i],w[i]));
    }
    
    long long ans = -1;
    
    for(int i = 0;i < n - 1;++i){
        int n1 = 0,n2 = 0;
        long long C1 = 0,su1 = 0;
        
        dfs(u[i],v[i],n1,0,C1);
        m = n1;
        dfs2(u[i],v[i],-1,su1,C1,C1);
        
        long long C2 = 0,sv1 = 0;
        
        dfs(v[i],u[i],n2,0,C2);
        m = n2;
        dfs2(v[i],u[i],-1,sv1,C2,C2);
        
        long long aux = C1 * n2 + C2 * n1 + (long long)w[i] * n1 * n2 + su1 + sv1;
        if(ans == -1 || aux < ans) ans = aux;
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
