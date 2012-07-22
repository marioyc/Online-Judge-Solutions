#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int M,N;
    
    while(true){
        scanf("%d %d",&M,&N);
        
        if(M == 0) break;
        
        bool first = true;
        
        while(M > 0){
            int x = (N + M - 1) / M;
            
            while(true){
                long long num = (long long)M * x - N;
                long long den = (long long)N * x;
                long long g = __gcd(num,den);
                
                num /= g; den /= g;
                
                if(den < 1000000){
                    M = num;
                    N = den;
                    
                    if(!first) putchar(' ');
                    first = false;
                    
                    printf("%d",x);
                    
                    break;
                }
                
                ++x;
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
