#include <cstdio>
#include <cstring>

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
    while(true){
        scanf("%s",P);
        n = strlen(P);
        
        if(n==1 && P[0]=='.') break;
        
        prefixFunction();
        
        int p = n-f[n-1];
        
        if(n%p==0 && p<n) printf("%d\n",n/p);
        else printf("1\n");
    }
    
    return 0;
}
