#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 50000

int A[MAX_N],B[MAX_N];

vector<int> adj[MAX_N],W[MAX_N];
int Q[MAX_N],head,tail;
bool visited[MAX_N];
int firstSon[MAX_N],nextBrother[MAX_N];

int dp1[MAX_N][2],dp2[MAX_N][2];
int path[2][MAX_N],L[2];

int main(){
    int N,E;
    scanf("%d %d",&N,&E);
    
    for(int i = 0;i<N;++i) scanf("%d",&A[i]);
    
    for(int i = 0,a,b,c;i<E;++i){
        scanf("%d %d %d",&a,&b,&c);
        --a; --b;
        adj[a].push_back(b);
        W[a].push_back(c);
        adj[b].push_back(a);
        W[b].push_back(c);
    }
    
    memset(B,0,sizeof(B));
    memset(visited,false,sizeof(visited));
    memset(firstSon,-1,sizeof(firstSon));
    memset(nextBrother,-1,sizeof(nextBrother));
    head = tail = 0;
    
    for(int i = 0;i<N;++i){
        if(visited[i]) continue;
        
        Q[tail] = i; ++tail;
        visited[i] = true;
        
        while(head<tail){
            int u = Q[head]; ++head;
            
            for(int i = adj[u].size()-1,prev = -1;i>=0;--i){
                int v = adj[u][i], w = W[u][i];
                if(visited[v]) continue;
                
                Q[tail] = v; ++tail;
                visited[v] = true;
                
                if(prev==-1) firstSon[u] = v;
                else nextBrother[prev] = v;
                
                prev = v;
                B[v] = W[u][i];
            }
        }
    }
    
    for(int i = N-1;i>=0;--i){
        int u = Q[i];
        
        for(int cap = 0;cap<2;++cap){
            dp1[u][cap] = A[u]+B[u]+(firstSon[u]==-1? 0 : dp2[firstSon[u]][cap]);
            
            if(nextBrother[u]==-1) dp2[u][cap] = dp1[u][0];
            else dp2[u][cap] = max(dp2[nextBrother[u]][cap],dp1[u][0]+(cap==0? 0 : dp2[nextBrother[u]][0]));
        }
    }
    
    int ans = -1,root = -1;
    
    for(int i = 0;i<N;++i){
        if(dp1[i][1]-B[i]>ans){
            ans = dp1[i][1]-B[i];
            root = i;
        }
    }
    
    printf("%d\n",ans);
    
    int chosen = -1;
    L[0] = L[1] = 0;
    
    for(int i = 0;i<2;++i){
        int pos = -1,best = -1;
        
        for(int u = firstSon[root];u!=-1;u = nextBrother[u]){
            if(dp1[u][0]>best && chosen!=u){
                pos = u;
                best = dp1[u][0];
            }
        }
        
        if(pos==-1) break;
        chosen = pos;
        path[i][0] = pos; ++L[i];
        
        while(firstSon[pos]!=-1){
            int aux = -1,best = -1;
            
            for(int u = firstSon[pos];u!=-1;u = nextBrother[u]){
                if(dp1[u][0]>best){
                    aux = u;
                    best = dp1[u][0];
                }
            }
            
            pos = path[i][L[i]] = aux; ++L[i];
        }
    }
    
    printf("%d\n",L[0]+1+L[1]);
    
    for(int i = L[0]-1;i>=0;--i) printf("%d ",path[0][i]+1);
    printf("%d",root+1);
    for(int i = 0;i<L[1];++i) printf(" %d",path[1][i]+1);
    printf("\n");
    
    return 0;
}
