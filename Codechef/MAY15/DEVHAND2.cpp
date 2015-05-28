#include <cstdio>

using namespace std;

#define MOD 1000000007

int K;

struct calc{
    long long pow,sum0,sum1,sum2;

    calc(){}

    calc(long long x, long long y, long long z, long long w):
        pow(x),sum0(y),sum1(z),sum2(w){}
};

calc solve(int N){
    if(N == 0)
        return calc(1,0,0,0);

    calc ret = solve(N / 2);

    ret.sum2 = ((ret.pow + 1) * ret.sum2 + 2 * (N / 2) * ret.pow % MOD * ret.sum1 + (long long)(N / 2) * (N / 2) % MOD * ret.pow % MOD * ret.sum0) % MOD;
    ret.sum1 = ((ret.pow + 1) * ret.sum1 + (N / 2) * ret.pow % MOD * ret.sum0) % MOD;
    ret.sum0 = (ret.pow + 1) * ret.sum0 % MOD;
    ret.pow = ret.pow * ret.pow % MOD;

    if(N & 1){
        ret.sum2 = (ret.sum2 + (long long)N * N % MOD * ret.pow % MOD * K) % MOD;
        ret.sum1 = (ret.sum1 + N * ret.pow % MOD * K) % MOD;
        ret.sum0 = (ret.sum0 + ret.pow * K) % MOD;
        ret.pow = (ret.pow * K) % MOD;
    }

    return ret;
}

int inv[] = {0, 1, 500000004, 333333336, 250000002, 400000003, 166666668, 142857144, 125000001, 111111112, 700000005, 818181824, 83333334, 153846155, 71428572, 466666670, 562500004, 352941179, 55555556, 157894738, 850000006, 47619048, 409090912, 739130440, 41666667, 280000002};

int main(){
    int T,N;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N,&K);

        if(K == 1) printf("0\n");
        else{
            calc ret = solve(N);

            long long ans = ret.sum0 * ret.sum0 % MOD * ret.sum0 % MOD;
            ans = (ans - 6 * ret.sum0 % MOD * (ret.sum1 - ret.sum0)) % MOD;
            ans = (ans - 3 * ret.sum0 % MOD * ret.sum0) % MOD;
            ans = (ans + 2 * ret.sum0) % MOD;
            ans = (ans + 12 * (ret.sum1 - ret.sum0)) % MOD;
            ans = (ans + 6 * (ret.sum2 - 3 * ret.sum1 + 2 * ret.sum0)) % MOD;
            
            calc ret2 = solve(N - 1);
            long long aux = ret.pow * (N * ret2.sum0 % MOD - ret2.sum1) % MOD;
            aux = (aux - ret.pow * (N - 1) % MOD * N) % MOD;
            aux = (aux + ret2.sum1) % MOD;
            if(aux < 0) aux += MOD;

            ans = (ans + 3LL * K * inv[K - 1] % MOD * aux) % MOD;

            if(ans < 0) ans += MOD;

            printf("%lld\n",ans);
        }
    }

    return 0;
}