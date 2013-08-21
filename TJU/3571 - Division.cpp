#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10000

struct line{
    int m,b;
    
    line(){}
    line(int _m, int _b):
        m(_m), b(_b){}
};

int a[MAXN],dp[2][MAXN],pos,sz;
line H[MAXN];

bool check(line &l1, line &l2, line &l3){
    return (l3.b - l2.b) * (l1.m - l3.m) > (l3.b - l1.b) * (l2.m - l3.m);
}

void insert(line l){
    while(sz >= 2 && !check(H[sz - 2],H[sz - 1],l)){
        if(pos == sz - 1) --pos;
        --sz;
    }
    H[sz++] = l;
}

int eval(line &l, int x){
    return l.m * x + l.b;
}

int solve(int x){
    while(pos + 1 < sz && eval(H[pos],x) > eval(H[pos + 1],x)) ++pos;
    return eval(H[pos],x);
}

int main(){
    int T,n,m;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        sort(a,a + n);
        n = unique(a,a + n) - a;
        
        printf("Case %d: ",tc);
        
        if(m >= n) printf("0\n");
        else{
            for(int i = 0;i < n;++i)
                dp[1][i] = (a[i] - a[0]) * (a[i] - a[0]);
            
            for(int i = 2,r = 0;i <= m;++i,r ^= 1){
                sz = pos = 0;
                
                for(int j = 0;j < n;++j){
                    if(j < i) dp[r][j] = 0;
                    else dp[r][j] = a[j] * a[j] + solve(a[j]);
                    
                    if(j + 1 < n) insert(line(-2 * a[j + 1],a[j + 1] * a[j + 1] + dp[r ^ 1][j]));
                }
            }
            
            printf("%d\n",dp[m & 1][n - 1]);
        }
    }
    
    return 0;
}
