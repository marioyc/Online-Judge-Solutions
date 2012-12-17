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
    
    for(int i = 0;i < N;++i)
        b[i] = a[i] + N - 1 - i;
    
    int mx1[N],mx2[N];
    
    mx1[0] = b[0];
    
    for(int i = 1;i < N;++i)
        mx1[i] = max(mx1[i - 1],b[i]);
    
    mx2[N - 1] = b[N - 1] + 1;
    
    for(int i = N - 2;i >= 0;--i)
        mx2[i] = max(mx2[i + 1],b[i] + 1);
    
    int ans = 0;
    
    for(int i = 0;i < N;++i){
        int best = 0;
        if(i) best = max(best,mx1[i - 1]);
        if(i + 1 < N) best = max(best,mx2[i + 1]);
        if(a[i] + N >= best) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
