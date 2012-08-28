#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,x[100000];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&x[i]);
    
    int g = x[1] - x[0];
    
    for(int i = 1;i + 1 < N;++i)
        g = __gcd(g,x[i + 1] - x[i]);
    
    int ans = 0;
    
    for(int i = 0;i + 1 < N;++i)
        ans += (x[i + 1] - x[i]) / g - 1;
    
    printf("%d\n",ans);
    
    return 0;
}
