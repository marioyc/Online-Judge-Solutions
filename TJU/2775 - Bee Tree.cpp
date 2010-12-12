#include <cstdio>

using namespace std;

int main(){
    int T,n;
    scanf("%d",&T);
    
    long long M[41],F[41];
    M[0] = F[0] = 1;
    
    for(int i = 1;i<=40;++i){
        M[i] = F[i-1];
        F[i] = M[i-1]+F[i-1];
    }
    
    while(T--){
        scanf("%d",&n);
        printf("%lld %lld\n",M[n],F[n]);
    }
    
    return 0;
}
