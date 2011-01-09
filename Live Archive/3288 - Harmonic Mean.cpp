#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d",&N);
        
        long long num = 0,den = 1;
        
        for(int i = 0,x;i<N;++i){
            scanf("%d",&x);
            
            num = num*x+den;
            den *= x;
        }
        
        den *= N;
        
        long long g = __gcd(num,den);
        num /= g; den /= g;
        
        printf("Case %d: %lld/%lld\n",tc,den,num);
    }
    
    return 0;
}
