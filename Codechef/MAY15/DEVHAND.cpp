#include <cstdio>

using namespace std;

#define MOD 1000000007

int main(){
    int T,N,K;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N,&K);

        long long dp1 = 1 + K;
        long long dp2 = K * (K - 1);
        long long dp3 = K * (K - 1) * (K - 2);

        for(int i = 2;i <= N;++i){
            dp3 = (K * dp3 + 3 * K * (K - 1) * dp1 % MOD * dp2 + K * (K - 1) * (K - 2) * dp1 % MOD * dp1 % MOD * dp1) % MOD;
            dp2 = (K * dp2 + K * (K - 1) * dp1 % MOD * dp1) % MOD;
            dp1 = (dp1 * K + 1) % MOD;
        }

        printf("%lld\n",dp3);
    }

    return 0;
}