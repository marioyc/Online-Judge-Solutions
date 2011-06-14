#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[1000],dp[1000],nxt[1000];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    sort(a,a+N);
    
    int best = 0,ind = -1;
    
    for(int i = N-1;i >= 0;--i){
        dp[i] = 1;
        nxt[i] = -1;
        
        for(int j = i+1;j < N;++j){
            if(a[j] % a[i] == 0 && 1 + dp[j] > dp[i])
                dp[i] = 1+dp[j], nxt[i] = j;
        }
        
        if(dp[i] >= best){
            best = dp[i];
            ind = i;
        }
    }
    
    printf("%d\n",best);
    
    for(int i = 0,j = ind;i < best;++i,j = nxt[j]){
        if(i > 0) putchar(' ');
        printf("%d",a[j]);
    }
    
    putchar('\n');
    
    return 0;
}
