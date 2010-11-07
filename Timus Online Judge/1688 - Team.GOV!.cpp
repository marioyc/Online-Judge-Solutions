#include <cstdio>

using namespace std;

int main(){
    long long n,x;
    int m;
    
    scanf("%lld %d",&n,&m);
    n *= 3;
    
    for(int i = 0;i<m;++i){
        scanf("%lld",&x);
        n -= x;
        if(n<0){
            printf("Free after %d times.\n",i+1);
            break;
        }
    }
    
    if(n>=0) printf("Team.GOV!\n");
    
    return 0;
}
