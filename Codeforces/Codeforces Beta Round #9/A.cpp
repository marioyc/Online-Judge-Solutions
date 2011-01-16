#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int Y,W;
    scanf("%d %d",&Y,&W);
    
    int num = 7-max(Y,W),den = 6;
    int g = __gcd(num,den);
    
    num /= g; den /= g;
    
    printf("%d/%d\n",num,den);
    
    return 0;
}
