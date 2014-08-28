#include <cstdio>
#include <algorithm>

using namespace std;

long long sum[1001][1001];

int main(){
    for(int i = 1;i <= 1000;++i)
        for(int j = 1;j <= 1000;++j)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + __gcd(i,j) - 1;
    
    for(int i = 1;i <= 1000;++i)
        for(int j = 1;j <= 1000;++j)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    
    int n,m;
    long long nm;
    
    while(scanf("%d %d",&n,&m) == 2){
        nm = (long long)(n + 1) * (m + 1);
        printf("%lld\n",nm * ((nm - 1) * (nm - 2) - n * (n - 1) - m * (m - 1)) / 6 - 2 * sum[n][m]);
    }
    
    return 0;
}
