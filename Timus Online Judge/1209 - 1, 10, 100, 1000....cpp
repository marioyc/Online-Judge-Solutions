#include <cstdio>
#include <cmath>

using namespace std;

// Para un x si existe un entero positivo n tal que:
// n^2-n+2 = 2x -> (2n-1)^2 = 8x-7
// entonces el número en la posición x será un 1

int main(){
    int N;
    scanf("%d",&N);
    
    long long K;
    
    while(N--){
        scanf("%lld",&K);
        long long D = (long long)8*K-7;
        long long lo = 1,hi = D,mi;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(mi>D/mi) hi = mi-1;
            else lo = mi;
        }
        
        if(lo*lo==D && (lo & 1)==1) putc('1', stdout);
        else putc('0', stdout);
        putc(' ', stdout);
    }
    
    putc('\n', stdout);
    
    return 0;
}
