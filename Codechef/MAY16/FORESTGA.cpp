#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000

int H[MAXN],R[MAXN];

int main(){
    int N;
    long long W,L;

    scanf("%d %lld %lld",&N,&W,&L);

    for(int i = 0;i < N;++i){
        scanf("%d %d",&H[i],&R[i]);

        if(H[i] >= W){
            printf("0\n");
            return 0;
        }
    }

    long long lo = 0,hi = 1000000000000000000LL,mi;

    while(lo < hi){
        mi = lo + ((hi - lo) >> 1);

        long long sum = 0;

        for(int i = 0;i < N;++i){
            if(H[i] >= L || R[i] > (L - 1 - H[i]) / mi){
                long long have;
                if(R[i] <= (W - H[i]) / mi)
                    have = H[i] + R[i] * mi;
                else
                    have = W;
                sum = min(sum + have,W);
            }
        }

        if(sum == W) hi = mi;
        else lo = mi + 1;
    }

    printf("%lld\n",lo);

    return 0;
}
