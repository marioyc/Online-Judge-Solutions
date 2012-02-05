#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int INF = 100000000;

int main(){
    int T,N,F,M,Q,cont;
    int a[100],fa[100],b[100],fb[100],t[100];
    int qa,qfa,qb,qfb;
    vector<int> Lf[100];
    map< pair<int, int>, int> id;
    pair<int, int> P;
    int dist[300][300];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&F,&M);
        
        for(int i = 0;i < M;++i){
            scanf("%d %d %d %d %d",&a[i],&fa[i],&b[i],&fb[i],&t[i]);
            --a[i]; --fa[i]; --b[i]; --fb[i];
        }
        
        set<int> S[N];
        
        for(int i = 0;i < N;++i)
            S[i].insert(0);
        
        for(int i = 0;i < M;++i){
            S[a[i]].insert(fa[i]);
            S[b[i]].insert(fb[i]);
        }
        
        for(int i = 0;i < N;++i)
            Lf[i] = vector<int>(S[i].begin(),S[i].end());
        
        id.clear();
        cont = 0;
        
        for(int i = 0;i < N;++i){
            for(int j = Lf[i].size() - 1,to;j >= 0;--j){
                to = Lf[i][j];
                P = make_pair(i,to);
                
                if(id.find(P) == id.end()) id[P] = cont++;
            }
        }
        
        for(int i = 0;i < cont;++i){
            dist[i][i] = 0;
            
            for(int j = i + 1;j < cont;++j)
                dist[i][j] = dist[j][i] = INF;
        }
        
        for(int i = 0;i < M;++i){
            int u = id[make_pair(a[i],fa[i])];
            int v = id[make_pair(b[i],fb[i])];
            
            dist[u][v] = min(dist[u][v],t[i]);
            dist[v][u] = dist[u][v];
        }
        
        for(int i = 0,u,v;i < N;++i){
            for(int j = Lf[i].size() - 1;j >= 0;--j){
                u = id[make_pair(i,Lf[i][j])];
                
                for(int k = j - 1;k >= 0;--k){
                    v = id[make_pair(i,Lf[i][k])];
                    dist[u][v] = min(dist[u][v],abs(Lf[i][j] - Lf[i][k]));
                    dist[v][u] = dist[u][v];
                }
            }
        }
        
        for(int i = 0;i < N;++i){
            int u = id[make_pair(i,0)];
            int v = id[make_pair((i + 1) % N,0)];
            
            dist[u][v] = dist[v][u] = 1;
        }
        
        for(int k = 0;k < cont;++k)
            for(int i = 0;i < cont;++i)
                for(int j = 0;j < cont;++j)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        
        scanf("%d",&Q);
        
        while(Q--){
            int ans = INF;
            
            scanf("%d %d %d %d",&qa,&qfa,&qb,&qfb);
            --qa; --qfa; --qb; --qfb;
            
            if(qa == qb) ans = abs(qfa - qfb);
            
            for(int i = Lf[qa].size() - 1,u;i >= 0;--i){
                u = Lf[qa][i];
                
                for(int j = Lf[qb].size() - 1,v;j >= 0;--j){
                    v = Lf[qb][j];
                    
                    ans = min(ans,abs(u - qfa) + abs(v - qfb) + dist[id[make_pair(qa,u)]][id[make_pair(qb,v)]]);
                }
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
