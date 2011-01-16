#include <cstdio>

using namespace std;

int main(){
    int n,d;
    
    scanf("%d %d",&n,&d);
    
    int ans = 0,last;
    
    scanf("%d",&last);
    
    for(int i = 1,x;i<n;++i){
        scanf("%d",&x);
        
        if(x<=last){
            int k = (last-x+d-1)/d+((last-x)%d==0? 1 : 0);
            ans += k;
            x += d*k;
        }
        
        last = x;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
