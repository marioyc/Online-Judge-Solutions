#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAX_VAL = 1000000000000000000LL;
long long seq[66060];
int sz = 0;

int main(){
    for(long long p2 = 1;p2<MAX_VAL;p2 *= 2)
        for(long long p3 = 1;p2*p3<MAX_VAL;p3 *= 3)
            for(long long p5 = 1;p2*p3*p5<MAX_VAL;p5 *= 5)
                for(long long p7 = 1;p2*p3*p5*p7<MAX_VAL;p7 *= 7)
                    seq[sz++] = p2*p3*p5*p7;
    
    sort(seq,seq+sz);
    
    int T,ind;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&ind);
        printf("%lld\n",seq[ind-1]);
    }
    
    return 0;
}
