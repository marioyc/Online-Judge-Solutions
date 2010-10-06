#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int main(){
    int n,a[MAX_N],L,M[MAX_N+1];
    
    while(scanf("%d",&n)==1){
        for(int i = 0;i<n;++i)
            scanf("%d",&a[i]);
        
        int lo,hi,mi;
        
        L = M[0] = 0;
        
        for(int i = 0,j;i<n;++i){
            lo = 0; hi = L;
            
            while(lo!=hi){
                mi = (lo+hi+1)>>1;
                
                if(a[M[mi]]<a[i]) lo = mi;
                else hi = mi-1;
            }
            
            j = lo;
            
            if(j==L || a[i]<a[M[j+1]]){
                M[j+1] = i;
                L = max(L,j+1);
            }
        }
        
        printf("%d\n",L);
    }
    
    return 0;
}
