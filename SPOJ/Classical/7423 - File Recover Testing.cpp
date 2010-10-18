#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_L 1000000

char P[MAX_L+1];
int f[MAX_L];

void prefixFunction(){
    int n = strlen(P), k = 0;
    f[0] = 0;
    
    for(int i = 1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    int K;
    
    while(true){
        scanf("%d",&K);
        if(K==-1) break;
        
        scanf("%s",P);
        prefixFunction();
        
        int L = strlen(P),ans = 0;
        
        if(K>=L) ans = (K-f[L-1])/(L-f[L-1]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
