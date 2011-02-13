#include <cstdio>
#include <cmath>

using namespace std;

#define max(a,b) ((a)>(b)? (a) : (b))

long long sum(int N){
    long long ret = 0;
    
    double R = sqrt(N);
    int r = (int)floor(R);
    
    if(r*r==N) ret += N/r;
    
    for(int i = 1;i<R;++i){
        ret += N/i;
        ret += max(N/i-r,0);
    }
    
    return ret;
}

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%lld\n",sum(N)-N);
    }
    
    return 0;
}
