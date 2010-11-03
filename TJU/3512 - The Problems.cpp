#include <cstdio>
#include <cstring>

using namespace std;

int f[70],L;
char P[150][71],T[1000001];

void prefixFunction(int m){
    int n = strlen(P[m]), k = 0;
    f[0] = 0;
    
    for(int i=1;i<n;++i){
        while(k>0 && P[m][k]!=P[m][i]) k = f[k-1];
        if(P[m][k]==P[m][i]) ++k;
        f[i] = k;
    }
}

int count_kmp(int m){
    int n = strlen(P[m]), k = 0, ans = 0;
    
    for(int i=0;i<L;++i){
        while(k>0 && P[m][k]!=T[i]) k = f[k-1];
        if(P[m][k]==T[i]) ++k;
        
        if(k==n){
            ++ans;
            k = f[k-1];
        }
    }
    
    return ans;
}

int main(){
    int N,res[150],mx;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;++i) scanf("%s",P[i]);
        scanf("%s",T);
        L = strlen(T);
        
        mx = 0;
        
        for(int i=0;i<N;++i){
            prefixFunction(i);
            res[i] = count_kmp(i);
            if(res[i]>mx) mx = res[i];
        }
        
        printf("%d\n",mx);
        for(int i=0;i<N;++i) if(res[i]==mx) printf("%s\n",P[i]);
    }
    
    return 0;
}

