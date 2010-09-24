#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_V 1000

int V, num_scc, scc[MAX_V];
vector<int> G[MAX_V],GT[MAX_V];
bool visited[MAX_V];
stack<int> S;
queue<int> Q;

void dfs(int v){
   visited[v] = true;
   for(int i=G[v].size()-1;i>=0;--i)
       if(!visited[G[v][i]])
           dfs(G[v][i]);
   S.push(v);
}

void bfs(int v){
   Q.push(v);
   visited[v] = true;

   int aux;

   while(!Q.empty()){
       aux = Q.front();
       scc[aux] = num_scc;
       Q.pop();

       for(int i=GT[aux].size()-1;i>=0;i--){
           if(!visited[GT[aux][i]]){
               Q.push(GT[aux][i]);
               visited[GT[aux][i]] = true;
           }
       }
   }
}

void SCC(){
   memset(visited,false,sizeof(visited));

   for(int i=0;i<V;++i) if(!visited[i]) dfs(i);

   num_scc = 0;
   int aux;

   memset(visited,false,sizeof(visited));

   while(!S.empty()){
       aux = S.top();
       S.pop();

       if(!visited[aux]){
           bfs(aux);
           ++num_scc;
       }
   }
}

int main(){
   int T,M,x,y;
   scanf("%d",&T);

   for(int tc = 1;tc<=T;++tc){
       scanf("%d %d",&V,&M);

       for(int i = 0;i<V;++i) G[i].clear(), GT[i].clear();

       for(int i = 0;i<M;++i){
           scanf("%d %d",&x,&y);
           --x; --y;
           G[x].push_back(y);
           GT[y].push_back(x);
       }

       scanf("%d",&x);

       SCC();

       printf("%d\n",num_scc);
   }

   return 0;
}