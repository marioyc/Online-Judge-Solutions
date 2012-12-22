#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    long long f[41];
    
    f[0] = 1;
    f[1] = 1;
    f[2] = 5;
    
    for(int i = 3;i <= 40;++i)
        f[i] = f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3];
    
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    
    return 0;
}
