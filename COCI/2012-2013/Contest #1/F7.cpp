#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int a[N],b[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    sort(a,a + N);
    
    int mx[N];
    
    mx[N - 1] = a[N - 1] + 1;
    
    for(int i = N - 2;i >= 0;--i)
        mx[i] = max(mx[i + 1],a[i] + N - i);
    
    int ans = 0;
    
    for(int i = 0;i < N;++i){
        int best = 0;
        if(i + 1 < N) best = max(best,mx[i + 1]);
        if(a[i] + N >= best) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
