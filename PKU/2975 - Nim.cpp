#include <cstdio>

using namespace std;

int main(){
    int n,a[1000];
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        int sum = 0;
        
        for(int i = 0;i < n;++i){
            scanf("%d",&a[i]);
            sum ^= a[i];
        }
        
        int ans = 0;
        
        for(int i = 0;i < n;++i){
            sum ^= a[i];
            
            if(sum < a[i]) ++ans;
            
            sum ^= a[i];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
