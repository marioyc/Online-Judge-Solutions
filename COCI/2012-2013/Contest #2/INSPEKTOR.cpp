#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define SZ 300
#define INF (1LL << 59)

struct line{
    long long y0;
    int m;
    
    line(){}
    line(long long _y0, int _m):
        y0(_y0), m(_m){}
    
    bool operator < (line X)const{
        if(m != X.m) return m < X.m;
        return y0 < X.y0;
    }
};

bool check(line &a, line &b, line &c){
    return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
}

struct bucket{
    int m;
    line a[SZ];
    int am[SZ]; //sorted by slope
    int env[SZ],nenv; //envelope
    int cur;
    
    bucket(){
        m = 0;
        for(int i = 0;i < SZ;++i)
            a[i] = line(-INF,0);
    }
    
    void update(int pos, line val){
        for(int i = 0;i + 1 < m;++i)
            if(am[i] == pos) swap(am[i],am[i + 1]);
        
        if(m > 0 && am[m - 1] == pos) m--;
        
        a[pos] = val;
        am[m++] = pos;
        
        for(int i = m - 1;i > 0 && a[ am[i] ] < a[ am[i - 1] ];--i)
            swap(am[i],am[i - 1]);
        
        nenv = 0;
        cur = 0;
        
        for(int i = 0;i < m;++i){
            while(nenv >= 2 && !check(a[ env[nenv - 2] ],a[ env[nenv - 1] ],a[ am[i] ])) --nenv;
            env[nenv++] = am[i];
        }
    }
    
    long long eval(int pos, int t){
        if(a[pos].y0 == -INF) return -INF;
        return a[pos].y0 + (long long)a[pos].m * t;
    }
    
    long long query(int t){
        while(cur + 1 < nenv && eval(env[cur],t) < eval(env[cur + 1],t)) ++cur;
        return eval(env[cur],t);
    }
}B[MAXN / SZ + 1];

int main(){
    int N,Q;
    
    scanf("%d %d",&N,&Q);
    
    int op,T,K,Z,S,L,R;
    
    for(int q = 0;q < Q;++q){
        scanf("%d",&op);
        
        if(op == 1){
            scanf("%d %d %d %d",&T,&K,&Z,&S);
            --K;
            B[K / SZ].update(K % SZ,line(S - (long long)T * Z,Z));
        }else{
            scanf("%d %d %d",&T,&L,&R);
            --L; --R;
            
            if(L > R) swap(L,R);
            
            long long ans = -INF;
            
            while(L <= R && L % SZ != 0){
                ans = max(ans,B[L / SZ].eval(L % SZ,T));
                ++L;
            }
            
            while(L + SZ - 1 <= R){
                ans = max(ans,B[L / SZ].query(T));
                L += SZ;
            }
            
            while(L <= R){
                ans = max(ans,B[L / SZ].eval(L % SZ,T));
                ++L;
            }
            
            if(ans == -INF) printf("nema\n");
            else printf("%lld\n",ans);
        }
    }
    
    return 0;
}
