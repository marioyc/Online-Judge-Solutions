#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 200

double p[MAXN],p2[MAXN];
int N,K;
double memo[MAXN][2 * MAXN + 1];

double solve(int pos, int diff){
    if(pos == -1){
        if(diff == 0) return 1;
        return 0;
    }

    double &ret = memo[pos][diff + K];

    if(!(ret == ret)){
        ret = p2[pos] * solve(pos - 1,diff + 1) + (1 - p2[pos]) * solve(pos - 1,diff - 1);
    }

    return ret;
}

int main(){
    int T;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> N >> K;

        for(int i = 0;i < N;++i)
            cin >> p[i];
        sort(p,p + N);

        double ans = 0;

        for(int i = 0;i <= K;++i){
            int pos = 0;
            for(int j = 0;j < i;++j) p2[pos++] = p[j];
            for(int j = 0;j < K - i;++j) p2[pos++] = p[N - 1 - j];
            memset(memo,-1,sizeof memo);
            ans = max(ans,solve(K - 1,0));
        }

        printf("Case #%d: %.10f\n",tc,ans);
    }

    return 0;
}
