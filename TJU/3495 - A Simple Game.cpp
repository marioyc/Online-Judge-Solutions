#include <cstdio>
#include <algorithm>

using namespace std;

int N,T,a[30000];

int count(int x){
    int ret = 0;
    
    if(x==0){
        if(T<0) ret = N;
        else ret = 0;
    }else if(x>0){
        if(x*a[N-1]<=T) ret = 0;
        else{
            int lo = 0,hi = N-1,mi;
            
            while(lo<hi){
                mi = (lo+hi)>>1;
                
                if(x*a[mi]<=T) lo = mi+1;
                else hi = mi;
            }
            
            ret = N-lo;
        }
    }else{
        if(x*a[0]<=T) ret = 0;
        else{
            int lo = 0,hi = N-1,mi;
            
            while(lo<hi){
                mi = (lo+hi+1)>>1;
                
                if(x*a[mi]<=T) hi = mi-1;
                else lo = mi;
            }
            
            ret = lo+1;
        }
    }
    
    return ret;
}

int main(){
    for(int tc = 1;;++tc){
        scanf("%d %d",&N,&T);
        if(N==0) break;
        
        for(int i = 0;i<N;++i) scanf("%d",&a[i]);
        sort(a,a+N);
        
        int num = 0,dem = N*N;
        for(int i = 0;i<N;++i) num += count(a[i]);
        
        int g = __gcd(num,dem);
        num /= g; dem /= g;
        printf("Case %d: %d/%d\n",tc,num,dem);
    }
    
    return 0;
}
