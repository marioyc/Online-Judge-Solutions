#include <cstdio>

using namespace std;

int main(){
    int T,n,m;
    long long ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&m);
        
        ans=(long long)n*m-1;
        
        printf("%lld\n",ans);
    }
}
