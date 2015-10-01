#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 100005

struct CentroidDecomposition{
  vector<int> L[MAXN];
  int subsize[MAXN],cpar[MAXN];

  void dfs(int cur, int p){
    subsize[cur] = 1;

    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(to != p && cpar[to] == -1){
        dfs(to,cur);
        subsize[cur] += subsize[to];
      }
    }
  }

  void centroid_decomposition(int cur, int p, int n, int prevc){
    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(to != p && cpar[to] == -1 && 2 * subsize[to] > n){
        centroid_decomposition(to,cur,n,prevc);
        return;
      }
    }

    cpar[cur] = prevc;

    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(cpar[to] == -1){
        dfs(to,-1);
        centroid_decomposition(to,cur,subsize[to],cur);
      }
    }
  }

  void init(int start){
    memset(cpar,-1,sizeof cpar);
    dfs(start,-1);
    centroid_decomposition(start,-1,subsize[start],-2);
  }
}CD;

struct node{
  int pos,dist;

  node(){}
  node(int _pos, int _dist):
    pos(_pos), dist(_dist){}


  bool operator < (node X)const{
    return dist > X.dist;
  }
};

int p[17][MAXN],tin[MAXN],tout[MAXN],h[MAXN],cont;

void dfs(int cur, int par, int curh){
  p[0][cur] = par;
  h[cur] = curh;
  tin[cur] = cont++;

  for(int i = 1;i <= 16;++i)
    p[i][cur] = p[i - 1][ p[i - 1][cur] ];

  for(int i = 0;i < CD.L[cur].size();++i){
    int to = CD.L[cur][i];

    if(to != par)
      dfs(to,cur,curh + 1);
  }

  tout[cur] = cont++;
}

inline bool is_ancestor(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
  if(is_ancestor(u,v)) return u;
  if(is_ancestor(v,u)) return v;

  for(int i = 16;i >= 0;--i)
    if(!is_ancestor(p[i][u],v))
      u = p[i][u];

  return p[0][u];
}

int dist(int u, int v){
  return h[u] + h[v] - 2 * h[lca(u,v)];
}

priority_queue<node> Q[MAXN];
bool white[MAXN];

int distW(int x){
  priority_queue<node> &q = Q[x];

  while(!q.empty()){
    node cur = q.top();

    if(!white[cur.pos]){
      q.pop();
    }else{
      return cur.dist;
    }
  }

  return 100000;
}

int main(){
  int N,queries;

  scanf("%d",&N);

  for(int i = 1,u,v;i < N;++i){
    scanf("%d %d",&u,&v);
    CD.L[u].push_back(v);
    CD.L[v].push_back(u);
  }

  CD.init(1);
  dfs(1,1,0);

  scanf("%d",&queries);
  fflush(stdout);
  int op,x;

  while(queries--){
    scanf("%d %d",&op,&x);

    if(op == 0){
      white[x] = !white[x];

      if(white[x]){
        int cur = x;

        while(cur != -2){
          Q[cur].push(node(x,dist(x,cur)));
          cur = CD.cpar[cur];
        }
      }
    }else{
      int ans = 100000,cur = x;

      while(cur != -2){
        ans = min(ans,dist(x,cur) + distW(cur));
        cur = CD.cpar[cur];
      }

      printf("%d\n",ans == 100000? -1 : ans);
    }
  }

  return 0;
}
