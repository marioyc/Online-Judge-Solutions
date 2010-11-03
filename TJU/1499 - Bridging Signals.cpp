#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n;
    scanf("%d",&T);
    
    int L,M[40001],X[40000];
    int lo,hi,mi;
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",&X[i]);
        
        L = 0;
        M[0] = 0;
        
        for(int i=0,j;i<n;i++){
             lo = 0; hi = L;
             while(lo!=hi){
                  mi = (lo+hi+1)/2;
                  if(X[M[mi]]<X[i]) lo = mi;
                  else hi = mi-1;
             }
             j = lo;
             if(j==L || X[i]<X[M[j+1]]){
                  M[j+1] = i;
                  L = max(L,j+1);
             }
        }
        
        printf("%d\n",L);
    }
    
    return 0;
}
