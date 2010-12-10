#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long long a,b;
    int c;
    
    while(scanf("%lld %lld %d",&a,&b,&c)==3){
        long long ans = ((b+c)/c-(a-1+c)/c)/2  + (c%2==0? (b+c-c/2)/c-(a-1+c-c/2)/c : 0)/2;
        
        for(int i = 1;i<c-i;++i)
            ans += min((b+c-i)/c-(a+c-1-i)/c,(b+c-c+i)/c-(a-1+c-c+i)/c);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
