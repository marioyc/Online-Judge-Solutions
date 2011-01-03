#include<cstdio>

using namespace std;

int main(){    
    int x;
    long long ans;
    
    while(scanf("%d",&x)==1){
        ans=1;
        ans=ans*x*(x+1)/2;
        ans=ans*x*(x+1)/2;
        printf("%lld\n",ans);
    }
    
    return 0;
}
