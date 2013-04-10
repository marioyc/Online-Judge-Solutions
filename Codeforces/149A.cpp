#include <cstdio>

using namespace std;

int main(){
    int k,a[12],ans = -1;
    
    scanf("%d",&k);
    
    for(int i = 0;i < 12;++i)
        scanf("%d",&a[i]);
    
    for(int mask = 0;mask < (1 << 12);++mask){
        int sum = 0,cont = 0;
        
        for(int i = 0;i < 12;++i)
            if(mask >> i & 1){
                sum += a[i];
                ++cont;
            }
        
        if(sum >= k && (ans == -1 || cont < ans)) ans = cont;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
