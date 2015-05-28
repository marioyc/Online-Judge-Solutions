#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MOD 1000000007

int N,S[MAXN];

int main(){
    int T;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&N);

        for(int i = 0;i < N;++i)
            scanf("%d",&S[i]);

        sort(S,S + N);

        int prev = 1,cur,ans = 0;

        for(int i = N - 1;i >= 0;--i){
            ans = ans << 1;
            if(ans >= MOD) ans -= MOD;
            ans += S[i];
            if(ans >= MOD) ans -= MOD;
        }

        int aux = 0;

        for(int i = 0;i < N;++i){
            aux <<= 1;
            if(aux >= MOD) aux -= MOD;
            aux += S[i];
            if(aux >= MOD) aux -= MOD;
        }

        ans -= aux;

        if(ans < 0) ans += MOD;
        printf("%d\n",ans);
    }

    return 0;
}
