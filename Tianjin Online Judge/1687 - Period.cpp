#include <cstdio>

using namespace std;

#define MAX_L 1000000

int n,f[MAX_L];
char P[MAX_L+1];

void prefixFunction(){
    int k = 0;
    f[0] = 0;
    for(int i=1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    int tc=1;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        scanf("%s",P);
        
        prefixFunction();
        
        printf("Test case #%d\n",tc);
        ++tc;
        
        for(int i=2;i<=n;++i){
            int p = i-f[i-1];
            if(i%p==0 && p<i) printf("%d %d\n",i,i/p);
        }
        
        printf("\n");
    }
    
    return 0;
}
