#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[100000],b[100000];
    
    while(scanf("%d",&N)==1){
        for(int i = 0;i<N;++i) scanf("%d",&a[i]);
        for(int i = 0;i<N;++i) scanf("%d",&b[i]);
        
        sort(a,a+N);
        sort(b,b+N);
        
        int posa = 0,nega = 0,posb = 0,negb = 0;
        
        for(int i =0;i<N;++i){
            if(a[i]>0) ++posa;
            if(a[i]<0) ++nega;
            if(b[i]>0) ++posb;
            if(b[i]<0) ++negb;
        }
        
        int m1 = min(nega,posb),m2 = min(posa,negb);
        long long ans = -1000000000000000000LL;
        
        for(int i = 0;i<m1;++i)
            ans = max(ans,(long long)a[i]*b[N-m1+i]);
        
        for(int i = 0;i<m2;++i)
            ans = max(ans,(long long)b[i]*a[N-m2+i]);
        
        for(int i = m1,j = N-m1-1;i<N-m2;++i,--j)
            ans = max(ans,(long long)a[i]*b[j]);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
