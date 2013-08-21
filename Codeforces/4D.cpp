#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,w,h;
    
    scanf("%d %d %d",&n,&w,&h);
    
    pair< pair<int, int>, int > a[n];
    int dp[n],choose[n];
    
    for(int i = 0;i < n;++i){
        scanf("%d %d",&a[i].first.first,&a[i].first.second);
        a[i].second = i + 1;
    }
    
    sort(a,a + n);
    
    for(int i = n - 1;i >= 0;--i){
        dp[i] = 1;
        
        for(int j = i + 1;j < n;++j)
            if(a[j].first.first > a[i].first.first && a[j].first.second > a[i].first.second && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                choose[i] = j;
            }
    }
    
    int ans = 0,pos = 0;
    
    for(int i = 0;i < n;++i){
        if(a[i].first.first > w && a[i].first.second > h && dp[i] > ans){
            ans = dp[i];
            pos = i;
        }
    }
    
    printf("%d\n",ans);
    
    if(ans){
        for(int i = 0;i < ans;++i){
            printf("%d ",a[pos].second);
            pos = choose[pos];
        }
        printf("\n");
    }
    
    return 0;
}
