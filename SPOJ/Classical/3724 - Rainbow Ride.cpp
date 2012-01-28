#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> L[1000];
bool visited[1000];
int w[1000],compW[1000],sz[1000];
int memo[1000][1001];

int solve(int pos, int C){
    if(pos == -1) return 0;
    
    int &ret = memo[pos][C];
    
    if(ret == -1){
        ret = solve(pos - 1,C);
        
        if(compW[pos] <= C) ret = max(ret,sz[pos] + solve(pos - 1,C - compW[pos]));
    }
    
    return ret;
}

int main(){
    int N,C;
    
    while(true){
        scanf("%d %d",&N,&C);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&w[i]);
            L[i].clear();
        }
        
        for(int i = 0,m,x;i < N;++i){
            scanf("%d",&m);
            
            for(int j = 0;j < m;++j){
                scanf("%d",&x);
                L[i].push_back(x - 1);
                L[x - 1].push_back(i);
            }
        }
        
        memset(visited,false,sizeof visited);
        
        int m = 0;
        
        for(int i = 0;i < N;++i){
            if(!visited[i]){
                queue<int> Q;
                compW[m] = sz[m] = 0;
                
                Q.push(i);
                visited[i] = true;
                
                while(!Q.empty()){
                    int aux = Q.front();
                    Q.pop();
                    
                    compW[m] += w[aux];
                    ++sz[m];
                    
                    for(int j = L[aux].size() - 1,to;j >= 0;--j){
                        to = L[aux][j];
                        
                        if(!visited[to]){
                            Q.push(to);
                            visited[to] = true;
                        }
                    }
                }
                
                ++m;
            }
        }
        
        memset(memo,-1,sizeof memo);
        printf("%d\n",solve(m - 1,C));
    }
    
    return 0;
}
