#include <cstdio>
#include <algorithm>

using namespace std;

int N,a[100000],pos[100001],bit[100001];

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    long long inv = 0;
    
    for(int i = 0;i < N;++i){
        inv += i;
        
        for(int x = a[i];x > 0;x -= x & -x)
            inv -= bit[x];
        
        for(int x = a[i];x <= N;x += x & -x)
            ++bit[x];
        
        pos[ a[i] ] = i;
    }
    
    long long ans = inv;
    
    for(int i = 1;i < N;++i){
        inv += N - 2 * pos[i] - 1;
        ans = min(ans,inv);
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
