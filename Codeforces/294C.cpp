#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int C[1001][1001];
int a[1002];

int mod_pow(long long a, int b){
    if(b == -1) return 1;
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    for(int i = 0;i <= 1000;++i){
        C[i][0] = C[i][i] = 1;
        
        for(int j = 1;j < i;++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    a[0] = 0;
    for(int i = 1;i <= m;++i)
        scanf("%d",&a[i]);
    a[m + 1] = n + 1;
    m += 2;
    
    sort(a,a + m);
    
    long long ans = 1;
    int sum = 0;
    
    for(int i = 1;i < m;++i){
        if(i > 1 && i < m - 1)
            ans = ans * mod_pow(2,a[i] - a[i - 1] - 2) % MOD;
        sum += a[i] - a[i - 1] - 1;
    }
    
    for(int i = 1;i < m;++i){
        ans = ans * C[sum][ a[i] - a[i - 1] - 1 ] % MOD;
        sum -= a[i] - a[i - 1] - 1;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
