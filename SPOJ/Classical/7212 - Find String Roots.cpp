#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_L 100001
char P[MAX_L];
int f[MAX_L];

void prefixFunction(){
    int n = strlen(P), k = 0;
    f[0] = 0;
	
    for(int i=1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    while(true){
        scanf("%s",P);
        if(P[0]=='*') break;
        
        int L = strlen(P),ans = 1;
        prefixFunction();
        int s = L-f[L-1];
        
        if(s<L && L%s==0) ans = L/s;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
