#include <cstdio>

using namespace std;

#define MOD 1000000007
#define MAXN 100000

struct Matrix{
    long long a,b,c,d;
    
    Matrix():
        a(1), b(0), c(0), d(1){}
    
    Matrix(long long _a, long long _b, long long _c, long long _d):
        a(_a), b(_b), c(_c), d(_d){}
    
    Matrix operator * (Matrix X){
        return Matrix(
            (a * X.a + b * X.c) % MOD,
            (a * X.b + b * X.d) % MOD,
            (c * X.a + d * X.c) % MOD,
            (c * X.b + d * X.d) % MOD);
    }
};

int a[MAXN];
Matrix T[4 * MAXN];

void init(int node, int l, int r){
    if(l == r) T[node] = Matrix(0,a[l],1,1);
    else{
        int mi = (l + r) >> 1;
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
        T[node] = T[2 * node + 1] * T[2 * node + 2];
    }
}

Matrix query(int node, int l, int r, int x, int y){
    if(r < x || l > y) return Matrix();
    if(x <= l && r <= y) return T[node];
    int mi = (l + r) >> 1;
    return query(2 * node + 1,l,mi,x,y) * query(2 * node + 2,mi + 1,r,x,y);
}

int main(){
    int T,N,M,l,r;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        init(0,0,N - 1);
        
        while(M--){
            scanf("%d %d",&l,&r);
            --l; --r;
            
            if(r <= l + 1) printf("%d\n",a[r]);
            else{
                Matrix aux = query(0,0,N - 1,l + 2,r);
                printf("%lld\n",(aux.b * a[l] + aux.d * a[l + 1]) % MOD);
            }
        }
    }
    
    return 0;
}
