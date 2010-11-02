#include <cstdio>

using namespace std;

int main(){
    int n,p;
    
    while(true){
        scanf("%d %d",&n,&p);
        if(n==0 && p==0) break;
        
        long long ans = 1;
        
        for(int i = 2;i<=n;++i)
            ans = (ans*i)%p;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
