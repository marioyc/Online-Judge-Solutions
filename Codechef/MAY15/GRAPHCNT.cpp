#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXV 100000
#define LG_MAXV 16

struct DominatorTree{
    int root,V;
    vector<int> L[MAXV],Lrev[MAXV];
    int parent[MAXV],height[MAXV],dfsNum[MAXV],dfsPath[MAXV],cont;
    int sdom[MAXV],idom[MAXV];

    void init(int _V, int _root){
        V = _V; root = _root;
    }

    void dfs(int cur){
        dfsNum[cur] = cont;
        dfsPath[cont] = cur;
        ++cont;

        for(int i = (int)L[cur].size() - 1;i >= 0;--i){
            int to = L[cur][i];

            if(dfsNum[to] == -1){
                parent[to] = cur;
                height[to] = height[cur] + 1;
                sdom[to] = dfsNum[cur];
                dfs(to);
            }else if(dfsNum[cur] < dfsNum[to]){
                sdom[to] = min(sdom[to],dfsNum[cur]);
            }else if(to != cur){
                Lrev[to].push_back(cur);
            }
        }
    }

    int uf_parent[MAXV],min_sdom[MAXV];

    int Find(int x){
        if(uf_parent[x] != x){
            int p = uf_parent[x];
            uf_parent[x] = Find(uf_parent[x]);
            min_sdom[x] = min(min_sdom[x],min_sdom[p]);
        }

        return uf_parent[x];
    }

    void Union(int x, int y){
        uf_parent[x] = y;
        min_sdom[x] = min(min_sdom[x],min_sdom[y]);
    }

    int parent2[LG_MAXV + 1][MAXV],sdom2[LG_MAXV + 1][MAXV];

    int up_sdom(int x, int up){
        int ret = x;

        for(int i = 0;i <= LG_MAXV;++i){
            if(up >> i & 1){
                if(sdom[ sdom2[i][x] ] < sdom[ret])
                    ret = sdom2[i][x];
                
                x = parent2[i][x];
            }
        }

        return ret;
    }

    void dominator_tree(){
        memset(dfsNum,-1,sizeof dfsNum);
        parent[root] = root;
        height[root] = 0;
        cont = 0;
        dfs(root);

        for(int i = 0;i < V;++i)
            uf_parent[i] = i;

        vector<int> sdomOrder[V];

        for(int i = cont - 1;i > 0;--i){
            int cur = dfsPath[i];

            for(int j = (int)Lrev[cur].size() - 1;j >= 0;--j){
                int to = Lrev[cur][j];
                Find(to);
                sdom[cur] = min(sdom[cur],min_sdom[to]);
            }

            min_sdom[cur] = sdom[cur];

            for(int j = (int)L[cur].size() - 1;j >= 0;--j){
                int to = L[cur][j];

                if(parent[to] == cur)
                    Union(to,cur);
            }

            sdomOrder[ sdom[cur] ].push_back(cur);
        }

        for(int i = 0;i < V;++i){
            parent2[0][i] = parent[i];
            sdom2[0][i] = i;
        }

        for(int j = 1;j <= LG_MAXV;++j){
            for(int i = 0;i < V;++i){
                parent2[j][i] = parent2[j - 1][ parent2[j - 1][i] ];
                int x = sdom2[j - 1][i],y = sdom2[j - 1][ parent2[j - 1][i] ];
                sdom2[j][i] = (sdom[x] < sdom[y]? x : y);
            }
        }

        for(int i = 0;i < V;++i){
            for(int j = (int)sdomOrder[i].size() - 1;j >= 0;--j){
                int cur = sdomOrder[i][j];
                int aux = up_sdom(cur,height[cur] - height[ dfsPath[ sdom[cur] ] ]);
                idom[cur] = (sdom[aux] == sdom[cur]? dfsPath[ sdom[cur] ] : idom[aux]);
            }
        }
    }
}DT;

vector<int> L[MAXV];
int sz[MAXV];

void dfs(int cur){
    sz[cur] = 1;

    for(int i = (int)L[cur].size() - 1;i >= 0;--i){
        int to = L[cur][i];

        dfs(to);
        sz[cur] += sz[to];
    }
}

int main(){
    int N,M;

    scanf("%d %d",&N,&M);

    DT.init(N,0);

    for(int i = 0,u,v;i < M;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        DT.L[u].push_back(v);
    }

    DT.dominator_tree();

    for(int i = 1;i < N;++i)
        if(DT.dfsNum[i] != -1)
            L[ DT.idom[i] ].push_back(i);
    
    dfs(0);

    long long ans = (long long)DT.cont * (DT.cont - 1) / 2;

    for(int i = 1;i < N;++i)
        if(DT.dfsNum[i] != -1 && DT.idom[i] == 0)
            ans -= (long long)sz[i] * (sz[i] - 1) / 2;

    printf("%lld\n",ans);

    return 0;
}