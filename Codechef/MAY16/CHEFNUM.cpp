#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int memo[10][1 << 16][2][1 << 4],val[1 << 16];
int nd,d[10];

void conv(int x){
    if(x == 0){
        nd = 1;
        d[0] = 0;
    }else{
        nd = 0;
        while(x > 0){
            d[nd++] = x % 10;
            x /= 10;
        }
    }
}

int solve(int pos, int mask, int eq, int cur){
    if(pos == -1) return val[mask];

    int &ret = memo[pos][mask][eq][cur];

    if(ret == -1){
        ret = 0;
        int dmax = 9;
        if(eq == 1) dmax = d[pos];

        for(int i = 0;i <= dmax;++i){
            int nxt = (cur ^ i);
            ret += solve(pos - 1,(mask | (1 << nxt)),i == dmax? eq : 0,nxt);
            if(ret >= MOD) ret -= MOD;
        }
    }

    return ret;
}

int main(){
    for(int mask = 0;mask < (1 << 16);++mask){
        int aux = 0;

        for(int i = 0;i < 16;++i){
            if(mask >> i & 1){
                for(int j = i + 1;j < 16;++j){
                    if(mask >> j & 1)
                        aux |= (1 << (i ^ j));
                }
            }
        }

        for(int i = 0;i < 16;++i)
            if(aux >> i & 1)
                val[mask] += i;
    }

    int T,L,R;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&L,&R);
        --L;

        int ans = 0;
        conv(R);
        memset(memo,-1,sizeof memo);
        ans += solve(nd - 1,1,1,0);

        conv(L);
        memset(memo,-1,sizeof memo);
        ans -= solve(nd - 1,1,1,0);

        if(ans < 0) ans += MOD;

        printf("%d\n",ans);
    }

    return 0;
}
