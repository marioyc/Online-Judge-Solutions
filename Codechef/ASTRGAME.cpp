#include <cstdio>
#include <cstring>

using namespace std;

char S[31],w[30][31];
int N,L,Lw[30],memo[30][30];
bool isSubstring[30][30];

int grundy(int a, int b){
    if(a>b) return 0;
    int &ret = memo[a][b];
    
    if(ret==-1){
        bool have[901];
        memset(have,false,sizeof(have));
        
        for(int i = a;i<=b;++i){
            for(int j = 0;j<N;++j){
                if(isSubstring[j][i] && i+Lw[j]-1<=b){
                    int g = grundy(a,i-1) ^ grundy(i+Lw[j],b);
                    if(g<=900) have[g] = true;
                }
            }
        }
        
        for(int i = 0;i<=900;++i){
            if(!have[i]){
                ret = i;
                break;
            }
        }
    }
    
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",S);
        L = strlen(S);
        
        scanf("%d",&N);
        for(int i = 0;i<N;++i){
            scanf("%s",w[i]);
            Lw[i] = strlen(w[i]);
        }
        
        for(int i = 0;i<N;++i){
            for(int j = 0;j<L;++j){
                bool &valid = isSubstring[i][j];
                valid = true;
                
                if(j+Lw[i]-1>=L) valid = false;
                else{
                    for(int k = 0;k<Lw[i];++k)
                        if(S[j+k]!=w[i][k])
                            valid = false;
                }
            }
        }
        
        memset(memo,-1,sizeof(memo));
        
        if(grundy(0,L-1)) puts("Teddy");
        else puts("Tracy");
    }
    
    return 0;
}
