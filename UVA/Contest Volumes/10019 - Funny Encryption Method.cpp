#include <cstdio>
#include <cstring>

using namespace std;

int b1(int n){
    int ret = 0;
    
    while(n){
        if(n & 1) ++ret;
        n >>= 1;
    }
    
    return ret;
}

int d[4];

int b2(int n){
    int sz = 0;
    
    while(n){
        d[sz++] = n%10;
        n /= 10;
    }
    
    int m = 0;
    
    for(int i = 0;i<sz;++i)
        m = m*16+d[i];
    
    return b1(m);
}

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%d %d\n",b1(N),b2(N));
    }
    
    return 0;
}
