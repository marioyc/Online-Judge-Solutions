#include <cstdio>
#include <cstring>

using namespace std;

int f[1000000];
char P[1000001];

void prefixFunction(){
    int n = strlen(P),k = 0;
    f[0] = 0;
    
    for(int i = 1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    int T,MOD = 2006;
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",P);
        prefixFunction();
        
        int ans = 0,L = strlen(P);
        
        for(int i = 0;i<L;++i){
            if(f[i]==0 || (i+1)%(i+1-f[i])!=0) ans = (ans+1)%MOD;
            else ans = (ans+(i+1)/(i+1-f[i]))%MOD;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
