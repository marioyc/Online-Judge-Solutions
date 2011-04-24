#include <cstdio>
#include <cstring>

using namespace std;

char s[201];
int best[200][200],memo[200][200];

int solve(int s, int e){
    if(s > e) return 0;
    int &ret = memo[s][e];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = s;i <= e;++i){
            int aux = best[s][i] + solve(i+1,e);
            if(aux > ret) ret = aux;
        }
    }
    
    return ret;
}

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %s",&N,s);
        
        memset(best,0,sizeof(best));
        
        for(int i = 0;i < N;++i){
            for(int j = i;j < N;++j){
                for(int k = j,diff = 0;k >= i;--k){
                    if(s[k] == '1') ++diff;
                    else --diff;
                    
                    if(diff > 0) best[i][j] = j-k+1;
                }
            }
        }
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,N-1));
    }
    
    return 0;
}
