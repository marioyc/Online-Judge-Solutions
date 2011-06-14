#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    int ans = -1;
    
    for(int i = 0;i < N;++i)
        for(int j = i+1;j < N;++j)
            ans = max(ans,__gcd(a[i],a[j]));
    
    printf("%d\n",ans);
    
    return 0;
}
