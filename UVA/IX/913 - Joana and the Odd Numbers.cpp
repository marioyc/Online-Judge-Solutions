#include<cstdio>

using namespace std;

int main(){    
    int N;
    long long sum;
    
    while(scanf("%d",&N)==1){
        N>>=1;
        sum=-3+(long long)6*N*N+(long long)12*N;
        printf("%lld\n",sum);
    }
    
    return 0;
}
