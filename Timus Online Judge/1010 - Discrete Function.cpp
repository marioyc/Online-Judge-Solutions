#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100001

int n;
long long y[MAXN];

int main(){
    scanf("%d",&n);
    
    for(int i = 1;i <= n;++i)
        scanf("%lld",&y[i]);
    
    int ans = 1;
    
    for(int i = 2;i + 1 <= n;++i)
        if(abs(y[i + 1] - y[i]) > abs(y[ans + 1] - y[ans]))
            ans = i;
    
    printf("%d %d\n",ans,ans + 1);
    
    return 0;
}
