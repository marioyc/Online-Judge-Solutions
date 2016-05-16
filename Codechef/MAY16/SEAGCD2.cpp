#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> p;

bool is_prime(int n){
    for(int i = 3;i <= n / i;i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int M,memo[26][21][1 << 4],memo2[5][1 << 4],cont[101][1 << 4];

int solve2(int n, int mask){
    if(n < 0) return 0;
    if(mask == 0){
        if(n == 0) return 1;
        return 0;
    }

    int &ret = memo2[n][mask];

    if(ret == -1){
        int b = 31 - __builtin_clz(mask);
        mask ^= (1 << b);
        ret = solve2(n, mask);

        for(int x = 0;x < (1 << b);++x){
            if((mask & x) == x){
                int mask2 = (x | (1 << b));
                ret = (ret + (long long)solve2(n - 1,mask ^ x) * cont[M][mask2]) % MOD;
            }
        }

        mask ^= (1 << b);
    }

    return ret;
}

int solve(int n, int m, int mask){
    if(n < 0) return 0;
    if(m == -1){
        if(n > 4) return 0;
        return solve2(n,mask);
    }
    int &ret = memo[n][m][mask];

    if(ret == -1){
        ret = solve(n,m - 1,mask);

        for(int x = 0;x < (1 << 4);++x){
            if((mask & x) == x && M >= p[m]){
                ret = (ret + (long long)solve(n - 1,m - 1,(mask ^ x)) * cont[M / p[m]][x]) % MOD;
            }
        }
    }

    return ret;
}

int main(){
    for(int i = 11;i <= 100;i += 2){
        if(is_prime(i)){
            p.push_back(i);
        }
    }

    int p2[] = {2,3,5,7};

    for(int i = 1;i <= 100;++i){
        int mask = 0;
        int aux = i;

        for(int j = 0;j < 4;++j){
            int cur = p2[j];
            if(aux % cur == 0) mask |= (1 << j);
            while(aux % cur == 0) aux /= cur;
        }

        if(aux == 1){
            for(int j = i;j <= 100;++j)
                ++cont[j][mask];
        }
    }

    int T,N;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N,&M);
        memset(memo,-1,sizeof memo);
        memset(memo2,-1,sizeof memo2);

        int ret = 1;
        long long aux = 1;

        for(int i = 1;i <= 25 && i <= N;++i){
            aux *= (N + 1 - i);
            aux %= MOD;
            ret = (ret + aux * solve(i,20,(1 << 4) - 1)) % MOD;
        }

        printf("%d\n",ret);
    }

    return 0;
}
