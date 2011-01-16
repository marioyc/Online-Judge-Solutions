#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int A;
    scanf("%d",&A);
    
    int num = 0,den = A-2;
    
    for(int i = 2;i<A;++i){
        int aux = A;
        
        while(aux){
            num += aux%i;
            aux /= i;
        }
    }
    
    int g = __gcd(num,den);
    
    num /= g; den /= g;
    
    printf("%d/%d\n",num,den);
    
    return 0;
}
