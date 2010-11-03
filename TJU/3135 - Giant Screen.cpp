#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int R1,R2,S1,S2,n,r1,r2,s1,s2;
    long long p,ans = (1LL<<60);
    
    scanf("%d %d %d %d",&R1,&R2,&S1,&S2);
    scanf("%d",&n);
    
    for(int tc=1;tc<=n;++tc){
        scanf("%d %d %d %d %lld",&r1,&r2,&s1,&s2,&p);
        
        ans = min(ans,p*max(((R1+r1-1)/r1),((S1+s1-1)/s1))*max(((R2+r2-1)/r2),((S2+s2-1)/s2)));
        ans = min(ans,p*max(((R1+r2-1)/r2),((S1+s2-1)/s2))*max(((R2+r1-1)/r1),((S2+s1-1)/s1)));
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
