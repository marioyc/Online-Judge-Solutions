#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 500

vector<int> L[2 * MAXN];
stack<int> S;
int low[2 * MAXN],curh;
bool in_stack[2 * MAXN];
int cont_scc,id_scc[2 * MAXN];

void tarjan(int cur){
    S.push(cur);
    in_stack[cur] = true;
    low[cur] = ++curh;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(low[to] == -1){
            tarjan(to);
            low[cur] = min(low[cur],low[to]);
        }else if(in_stack[to]){
            low[cur] = min(low[cur],low[to]);
        }
    }
    
    if(low[cur] == curh){
        int nxt;
        
        do{
            nxt = S.top();
            S.pop();
            in_stack[nxt] = false;
            id_scc[nxt] = cont_scc;
        }while(nxt != cur);
        
        ++cont_scc;
    }
    
    --curh;
}

void build_scc(int V){
    memset(low,-1,sizeof low);
    memset(in_stack,false,sizeof in_stack);
    curh = cont_scc = 0;
    
    for(int i = 0;i < V;++i)
        if(low[i] == -1)
            tarjan(i);
}

int main(){
    int N,b[MAXN][MAXN];
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                scanf("%d",&b[i][j]);
        
        bool ok = true;
        
        for(int i = 0;i < N;++i){
            if(b[i][i] != 0) ok = false;
            
            for(int j = i + 1;j < N;++j)
                if(b[i][j] != b[j][i])
                    ok = false;
        }
        
        for(int p = 0;p < 31 && ok;++p){
            for(int i = 0;i < 2 * N;++i)
                L[i].clear();    
            
            for(int i = 0,i2 = 0;i < N;++i,i2 ^= 1){
                for(int j = 0,j2 = 0;j < N;++j,j2 ^= 1){
                    int x = ((b[i][j] >> p) & 1);
                    
                    if(i == j) ;
                    else if(i2 == 1 && j2 == 1){
                        if(x){
                            L[j + N].push_back(i);
                            L[i + N].push_back(j);
                        }else{
                            L[i].push_back(i + N);
                            L[j].push_back(j + N);
                        }
                    }else if(i2 == 0 && j2 == 0){
                        if(x){
                            L[i + N].push_back(i);
                            L[j + N].push_back(j);
                        }else{
                            L[i].push_back(j + N);
                            L[j].push_back(i + N);
                        }
                    }else{
                        if(x){
                            L[i].push_back(j + N);
                            L[j].push_back(i + N);
                            L[i + N].push_back(j);
                            L[j + N].push_back(i);
                        }else{
                            L[i].push_back(j);
                            L[j].push_back(i);
                            L[i + N].push_back(j + N);
                            L[j + N].push_back(i + N);
                        }
                    }
                }
            }
            
            build_scc(2 * N);
            
            for(int i = 0;i < N;++i)
                if(id_scc[i] == id_scc[i + N])
                    ok = false;
        }
        
        puts(ok? "YES" : "NO");
    }
    
    return 0;
}
