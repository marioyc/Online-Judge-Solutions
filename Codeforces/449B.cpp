#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 100005
#define MAXM 300000
#define MAXK 100000

int n,m,k;
int u[MAXM],v[MAXM],x[MAXM];
int s[MAXK],y[MAXK];
vector<int> L[MAXN],W[MAXN];
long long dist[MAXN];
bool out[MAXN];

int main(){
    scanf("%d %d %d",&n,&m,&k);
    
    for(int i = 0;i < m;++i){
        scanf("%d %d %d",&u[i],&v[i],&x[i]);
        L[ u[i] ].push_back(v[i]);
        W[ u[i] ].push_back(x[i]);
        L[ v[i] ].push_back(u[i]);
        W[ v[i] ].push_back(x[i]);
    }
    
    for(int i = 0;i < k;++i){
        scanf("%d %d",&s[i],&y[i]);
        L[1].push_back(s[i]);
        W[1].push_back(y[i]);
        L[ s[i] ].push_back(1);
        W[ s[i] ].push_back(y[i]);
    }
    
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > Q;
    memset(dist,-1,sizeof dist);
    
    Q.push(make_pair(0,1));
    dist[1] = 0;
    
    while(!Q.empty()){
        pair<long long, int> aux = Q.top();
        Q.pop();
        
        if(aux.first != dist[aux.second]) continue;
        
        int to;
        long long d;
        
        for(int i = L[aux.second].size() - 1;i >= 0;--i){
            to = L[aux.second][i];
            d = aux.first + W[aux.second][i];
            
            if(dist[to] == -1 || d < dist[to]){
                dist[to] = d;
                Q.push(make_pair(d,to));
            }
        }
    }
    
    for(int i = 0;i < m;++i){
        if(dist[ v[i] ] - dist[ u[i] ] == x[i]) out[ v[i] ] = true;
        else if(dist[ u[i] ] - dist[ v[i] ] == x[i]) out[ u[i] ] = true;
    }
    
    int cont = 0;
    
    for(int i = 2;i <= n;++i)
        if(!out[i])
            ++cont;
    
    printf("%d\n",k - cont);
    
    return 0;
}
