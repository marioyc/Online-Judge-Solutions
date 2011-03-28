#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,d[1000][1000],t[1000],C;
vector<int> comp[1000];
int Q[1000],head,tail;
bool visited[1000];

int main(){
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&d[i][j]);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&t[i]);
        
        C = 0;
        for(int i = 0;i < n;++i)
            comp[i].clear();
        
        memset(visited,false,sizeof(visited));
        
        for(int i = 0;i < n;++i){
            if(!visited[i]){
                head = tail = 0;
                
                visited[i] = true;
                Q[tail] = i;
                ++tail;
                
                while(head < tail){
                    int cur = Q[head];
                    comp[C].push_back(cur);
                    ++head;
                    
                    for(int j = 0;j < n;++j){
                        if(d[cur][j] != -1 && !visited[j]){
                            visited[j] = true;
                            Q[tail] = j;
                            ++tail;
                        }
                    }
                }
                
                ++C;
            }
        }
        
        int ans = 0;
        
        for(int c = 0;c < C;++c){
            int sz = comp[c].size();
            
            for(int k = 0;k < sz;++k){
                int x = comp[c][k];
                
                for(int i = 0;i < sz;++i){
                    int y = comp[c][i];
                    
                    if(d[x][y] != -1){
                        for(int j = 0;j < sz;++j){
                            int z = comp[c][j];
                            
                            if(d[x][z] != -1 && (d[y][z] == -1 || d[y][x]+d[x][z] < d[y][z]))
                                d[y][z] = d[y][x] + d[x][z];
                        }
                    }
                }
            }
            
            int comp_ans = -1;
            
            for(int i = 0;i < sz;++i){
                int aux = 0;
                
                for(int j = 0;j < sz;++j)
                    if(d[comp[c][i]][comp[c][j]] > aux)
                        aux = d[comp[c][i]][comp[c][j]];
                
                aux += t[comp[c][i]];
                
                if(comp_ans == -1 || aux < comp_ans) comp_ans = aux;
            }
            
            ans = max(ans,comp_ans);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
