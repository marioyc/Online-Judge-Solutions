#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T;
    long long A,B;

    scanf("%d",&T);

    while(T--){
        scanf("%lld %lld",&A,&B);

        while(A != 1 && B != 1){
            A = __gcd(A,B);
            B /= A;
        }

        if(B == 1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}