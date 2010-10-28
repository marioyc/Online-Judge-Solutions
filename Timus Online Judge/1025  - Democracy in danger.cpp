#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int K;
    scanf("%d",&K);
    
    int sz[101];
    for(int i = 0;i<K;++i)
        scanf("%d",&sz[i]);
    
    sort(sz,sz+K);
    
    int ans = 0;
    
    for(int i = 0;2*i<K;++i)
        ans += (sz[i]+2)/2;
    
    printf("%d\n",ans);
    
    return 0;
}
