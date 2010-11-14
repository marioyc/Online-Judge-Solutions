#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    
    printf("%d\n",min((M+N-K)/3,min(M/2,N)));
    
    return 0;
}
