#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int abs(int x){
    return (x<0? -x:x);
}

int main(){
    int n,ind1[MAX_N],ind2[MAX_N],A[MAX_N],x,N,M;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        N = M = 0;
        
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            
            if(x<0){
                ind1[N] = i;
                A[i] = -x;
                ++N;
            }else{
                ind2[M] = i;
                A[i] = x;
                ++M;
            }
        }
        
        long long ans = 0;
        
        for(int i=0,j=0;i<N;++i){
            while(A[ind1[i]]>0){
                x = min(A[ind1[i]],A[ind2[j]]);
                A[ind1[i]] -= x; A[ind2[j]] -= x;
                ans += (long long)x*abs(ind1[i]-ind2[j]);
                if(A[ind2[j]]==0) ++j;
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
