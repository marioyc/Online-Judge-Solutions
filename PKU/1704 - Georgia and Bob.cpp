#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,a[1000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        a[n++] = 0;
        
        sort(a,a + n);
        
        int ans = 0;
        
        for(int i = n - 2;i >= 0;i -= 2)
            ans ^= (a[i + 1] - a[i] - 1);
        
        puts(ans == 0? "Bob will win" : "Georgia will win");
    }
    
    return 0;
}
