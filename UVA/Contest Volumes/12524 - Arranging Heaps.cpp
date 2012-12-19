#include <cstdio>

using namespace std;

#define MAXN 1000

int N,K,X[MAXN],W[MAXN];
long long f[MAXN],g[MAXN];
long long dp[2][MAXN];

struct line{
    long long y0;
    int m;
    
    line(){}
    line(long long _y0, int _m):
        y0(_y0), m(_m){}
};

bool check(line a, line b, line c){
    return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
}

int nh,pos;
line H[MAXN];

void update(line l){
    while(nh >= 2 && !check(H[nh - 2],H[nh - 1],l)){
        if(pos == nh - 1) --pos;
        --nh;
    }
    
    H[nh++] = l;
}

long long eval(int id, int x){
    return H[id].y0 + (long long)H[id].m * x;
}

long long query(int x){
    while(pos + 1 < nh && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}

int main(){
    while(scanf("%d %d",&N,&K) == 2){
        for(int i = 0;i < N;++i)
            scanf("%d %d",&X[i],&W[i]);
        
        f[0] = W[0];
        g[0] = (long long)X[0] * W[0];
        
        for(int i = 1;i < N;++i){
            f[i] = f[i - 1] + W[i];
            g[i] = g[i - 1] + (long long)X[i] * W[i];
        }
        
        for(int i = 0;i < N;++i)
            dp[1][i] = X[i] * f[i] - g[i];
        
        for(int k = 2,r = 0;k <= K;++k,r ^= 1){
            nh = 0; pos = 0;
            
            for(int i = k - 1;i < N;++i){
                update(line(dp[r ^ 1][i - 1] + g[i - 1],-f[i - 1]));
                dp[r][i] = X[i] * f[i] - g[i] + query(X[i]);
            }
        }
        
        printf("%lld\n",dp[K & 1][N - 1]);
    }
    
    return 0;
}
