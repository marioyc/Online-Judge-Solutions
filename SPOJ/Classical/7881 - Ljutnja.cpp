#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long long M;
    int N;
    scanf("%lld %d",&M,&N);
    
    long long a[N];
    for(int i = 0;i<N;++i) scanf("%lld",&a[i]);
    sort(a,a+N);
    
    long long lo = 0,hi = a[N-1]-1,mi;
    
    while(lo!=hi){
        mi = (lo+hi+1)/2;
        
        long long M2 = M;
        
        for(int i = 0;i<N;++i)
            if(a[i]>mi)
                M2 -= a[i]-mi;
        
        if(M2>0) hi = mi-1;
        else lo = mi;
    }
    
    ++lo;
    
    for(int i = N-1;i>=0;--i){
        if(a[i]>lo){
            M -= a[i]-lo;
            a[i] -= a[i]-lo;
        }
    }
    
    --lo;
    
    for(int i = N-1;i>=0 && M>0;--i){
        if(a[i]>lo){
            --M;
            --a[i];
        }
    }
    
    long long ans = 0;
    for(int i = 0;i<N;++i) ans += a[i]*a[i];
    printf("%lld\n",ans);
    
    return 0;
}
