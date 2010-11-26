#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> L[100];
vector<int> W[100];
int memo[101][100];

int solve(int cur, int prev, int q){
    if(q==0) return 0;
    int &ret= memo[cur][q];
    
    if(ret==-1){
        int g = L[cur].size();
        ret = 0;
        
        if(g>1){
            for(int i = g-1;i>=0;--i){
                if(L[cur][i]==prev) continue;
                
                for(int j = i-1;j>=0;--j){
                    if(L[cur][j]==prev) continue;
                    
                    for(int k = 0;k<=q;++k){
                        ret = max(ret,(k==0? 0 : W[cur][i]+solve(L[cur][i],cur,k-1))+
                                (k==q? 0 : W[cur][j]+solve(L[cur][j],cur,q-k-1)));
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int N,Q;
    scanf("%d %d",&N,&Q);
    
    for(int i = 1,u,v,w;i<N;++i){
        scanf("%d %d %d",&u,&v,&w);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);
    }
    
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(0,-1,Q));
    
    return 0;
}
