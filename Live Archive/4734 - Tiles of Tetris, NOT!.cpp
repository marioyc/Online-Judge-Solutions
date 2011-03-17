#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int w,h;
    
    while(true){
        scanf("%d %d",&w,&h);
        if(w==0 && h==0) break;
        
        int g = __gcd(w,h);
        long long ans = (long long)(w/g)*(h/g);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
