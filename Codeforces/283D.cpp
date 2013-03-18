#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 5000

long long a[MAXN];
int p2[MAXN];

bool check(int i, int j){
    int &contx = p2[i],&conty = p2[j];
    if(a[i] % a[j] != 0) return false;
    if(conty == 0) return true;
    if(contx <= conty && conty - contx == j - i) return true;
    return conty + (contx == 0? 0 : 1) <= j - i;
}

int dp[MAXN];

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i){
        scanf("%I64d",&a[i]);
        
        while((a[i] & 1) == 0){
            a[i] >>= 1;
            ++p2[i];
        }
    }
    
    int ans = n;
    
    for(int i = 0;i < n;++i){
        dp[i] = i;
        
        for(int j = 0;j < i;++j)
            if(check(j,i))
                dp[i] = min(dp[i],dp[j] + i - j - 1);
        
        ans = min(ans,n - 1 - i + dp[i]);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
