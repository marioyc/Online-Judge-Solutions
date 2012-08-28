#include <cstdio>

using namespace std;

int main(){
    int T,n;
    unsigned long long f[41];
    
    f[1] = 2;
    
    for(int i = 2;i <= 40;++i)
        f[i] = 3 * f[i - 1] + 2;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        printf("%llu\n",f[n]);
    }
    
    return 0;
}
