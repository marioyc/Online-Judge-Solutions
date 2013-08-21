#include <cstdio>

using namespace std;

#define MOD 1000000007

int main(){
    int n;
    
    scanf("%d",&n);
    
    int ways[2],ans = 0;
    ways[0] = ways[1] = 0;
    
    for(int i = 0,p = 0;i < n;++i,p ^= 1){
        int cur = 1 + ways[p ^ 1];
        
        ans += cur;
        if(ans >= MOD) ans -= MOD;
        
        ways[p] += cur;
        if(ways[p] >= MOD) ways[p] -= MOD;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
