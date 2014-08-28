#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAXN 2005

int N,M,K,p[MAXN];
vector<int> L[MAXN];
int id[1000001],memo[MAXN][500];

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

int solve(int pos, int k){
    if(pos == N){
        if(k == K) return 1;
        return 0;
    }
    
    int &ret = memo[pos][ id[k] ];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = L[pos].size() - 1,to;i >= 0;--i){
            to = L[pos][i];
            
            if(id[ p[to] ] != -1){
                int aux = lcm(k,p[to]);
                
                if(aux != k){
                    ret += solve(to,aux);
                    if(ret >= MOD) ret -= MOD;
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int u,v;
    
    while(scanf("%d %d %d",&N,&M,&K) == 3){
        for(int i = 1;i <= N;++i)
            L[i].clear();
        
        for(int i = 0,u,v;i < M;++i){
            scanf("%d %d",&u,&v);
            L[u].push_back(v);
        }
        
        for(int i = 1;i <= N;++i)
            scanf("%d",&p[i]);
        
        memset(id,-1,sizeof id);
        int cont = 0;
        
        for(int i = 1;i <= K / i;++i){
            if(K % i == 0){
                id[i] = cont++;
                id[K / i] = cont++;
            }
        }
        
        memset(memo,-1,sizeof memo);
        printf("%d\n",K % p[1] == 0? solve(1,p[1]) : 0);
    }
    
    return 0;
}
