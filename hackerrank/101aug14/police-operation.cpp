#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[2000001];
int a[2000000];

struct line{
    long long a,b;
    
    line(){}
    line(long long _a, long long _b):
        a(_a),b(_b){}
};

line H[2000000];
int nh = 0,cur = 0;

void add(long long m, long long b){
    while(nh >= 2 && (b - H[nh - 2].b) * (H[nh - 2].a - H[nh - 1].a) <= (H[nh - 1].b - H[nh - 2].b) * (H[nh - 2].a - m)){
        --nh;
        cur = max(cur - 1,0);
    }
    
    H[nh++] = line(m,b);
}

long long eval(int pos, long long x){
    return H[pos].a * x + H[pos].b;
}

long long query(long long x){
    while(cur + 1 < nh && eval(cur + 1,x) < eval(cur,x)) ++cur;
    
    return eval(cur,x);
}

int main(){
    int n,h;
    
    scanf("%d %d",&n,&h);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    sort(a,a + n);
    
    dp[0] = 0;
    
    for(int i = 0;i < n;++i){
        add(-2 * a[i],(long long)a[i] * a[i] + dp[i] + h);
        
        dp[i + 1] = query(a[i]) + (long long)a[i] * a[i];
    }
    
    printf("%lld\n",dp[n]);
    
    return 0;
}
