#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    sort(a,a + n);
    
    long long ans = 0;
    
    for(int i = 0;i < n;++i)
        ans += abs(a[i] - i - 1);
    
    printf("%I64d\n",ans);
    
    return 0;
}
