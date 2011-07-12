#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long MAX_D = 1000000000;

// Numero de puntos enteros en el rectangulo
// (0,0) (MAX_D, MAX_D * A / B)

long long count(int A, int B){
    return ((MAX_D + 1) * (MAX_D * A / B + 1) - MAX_D / (B / __gcd(A,B))) / 2;
}

int main(){
    char s[10];
    
    while(true){
        scanf("%s",s);
        if(s[0] == '#') break;
        
        int K = strlen(s) - 2,X = 0,pot10 = 1;
        
        for(int i = 0;i < K;++i){
            X = X * 10 + s[i + 2] - '0';
            pot10 *= 10;
        }
        
        printf("%lld\n",count(2 * X + 1,2 * pot10) - count(2 * X - 1,2 * pot10));
    }
    
    return 0;
}
