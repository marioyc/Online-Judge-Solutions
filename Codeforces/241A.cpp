#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int m,k;
    
    scanf("%d %d",&m,&k);
    
    int d[m],s[m];
    
    for(int i = 0;i < m;++i) scanf("%d",&d[i]);
    for(int i = 0;i < m;++i) scanf("%d",&s[i]);
    
    int ans = 0,have = 0,best = 0;
    
    for(int i = 0;i < m;++i){
        best = max(best,s[i]);
        have += s[i];
        have -= d[i];
        ans += d[i];
        
        while(have < 0){
            have += best;
            ans += k;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
