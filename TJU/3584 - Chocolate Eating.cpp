#include <cstdio>

using namespace std;

int main(){
    int N,D;
    
    scanf("%d %d",&N,&D);
    
    int H[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&H[i]);
    
    long long lo = 0,hi = 50000000000LL,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        int pos = 0;
        long long cur = 0;
        bool ok = true;
        
        for(int i = 0;i < D && ok;++i){
            while(pos < N && cur < mi)
                cur += H[pos++];
            
            if(cur < mi) ok = false;
            cur >>= 1;
        }
        
        if(ok) lo = mi;
        else hi = mi - 1;
    }
    
    printf("%lld\n",lo);
    
    int pos = 0;
    long long cur = 0;
    
    for(int i = 0;i < D;++i){
        while(pos < N && cur < lo){
            cur += H[pos++];
            printf("%d\n",1 + i);
        }
        cur >>= 1;
    }
    
    while(pos < N){
        printf("%d\n",D);
        pos++;
    }
    
    return 0;
}
