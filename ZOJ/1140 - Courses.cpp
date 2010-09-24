#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXV1 = 100;
const int MAXV2 = 300;

vector<int> L[MAXV1];
bool visited[MAXV2];
int V1,V2,match[MAXV2];

bool dfs(int u){
     for(int i=L[u].size()-1;i>=0;--i){
          int v = L[u][i];
          
          if(!visited[v]){
                visited[v] = true;
                if(match[v]==-1 || dfs(match[v])){
                      match[v] = u;
                      return true;
                }
          }
     }
     return false;
}

int maximum_matching(){
     int ans = 0;
     memset(match,-1,sizeof(match));
     
     for(int i=0;i<V1;++i){
          memset(visited,false,sizeof(visited));
          ans += dfs(i);
     }
     
     return ans;
}

int main(){
     int T,m,s;
     scanf("%d",&T);
     
     while(T--){
          scanf("%d %d",&V1,&V2);
          
          for(int i=0;i<V1;++i) L[i].clear();
          
          for(int i=0;i<V1;++i){
                scanf("%d", &m);
                while(m--){
                    scanf("%d",&s);
                    L[i].push_back(s-1);
                }
          }
          
          if(maximum_matching()==V1) printf("YES\n");
          else printf("NO\n");
     }
     
     return 0;
}
