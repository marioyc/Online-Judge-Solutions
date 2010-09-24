#include<cstdio>

using namespace std;

int main(){    
    int T,n,m;
    long long sum;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d %d",&n,&m);
        
        sum=(long long)(m-n+1)*(m+n)/2;
        
        printf("Scenario #%d:\n%lld\n\n",i,sum);
    }
    
    return 0;
}
