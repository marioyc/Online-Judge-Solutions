#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int L,N,a[100000];
    char s[26];
    
    while(true){
        scanf("%d %d",&L,&N);
        if(L == -1) break;
        
        for(int i = 0;i < N;++i){
            scanf("%s",s);
            a[i] = strlen(s) + 1;
        }
        
        int lo = 0,hi = 26 * N,mi;
        L = min(L,N);
        
        while(lo != hi){
            mi = (lo + hi) / 2;
            
            int pos = 0;
            
            for(int i = 0;i < L && pos < N;++i){
                int aux = 0;
                
                while(pos < N && aux + a[pos] <= mi){
                    aux += a[pos];
                    ++pos;
                }
            }
            
            if(pos < N) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo - 1);
    }
    
    return 0;
}
