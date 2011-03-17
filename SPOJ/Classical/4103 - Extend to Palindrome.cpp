#include <cstdio>
#include <cstring>

using namespace std;

int L,pref[100000],k;
char T[100001],P[100001];

int main(){
    while(scanf("%s",T)==1){
        L = strlen(T);
        for(int i = 0,j = L-1;i<L;++i,--j) P[i] = T[j];
        
        pref[0] = 0;
        
        for(int i = 1;i<L;++i){
            k = pref[i-1];
            while(k>0 && P[k]!=P[i]) k = pref[k-1];
            if(P[k]==P[i]) ++k;
            pref[i] = k;
        }
        
        k = 0;
        
        for(int i = 0;i<L;++i){
            while(k>0 && P[k]!=T[i]) k = pref[k-1];
            if(P[k]==T[i]) ++k;
            
            if(i!=L-1 && k==L) k = pref[L-1];
        }
        
        printf("%s",T);
        for(int i = L-k-1;i>=0;--i) putchar(T[i]);
        putchar('\n');
    }
    
    return 0;
}
