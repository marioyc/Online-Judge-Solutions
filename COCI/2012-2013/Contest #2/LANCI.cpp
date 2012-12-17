#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 500000

int N,a[MAXN];

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    sort(a,a + N);
    
    long long ans = N - 1,sum = 0;
    
    for(int i = 0;i < N;++i){
        sum += a[i];
        ans = min(ans,sum + max(0LL,N - 2 - i - sum));
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
