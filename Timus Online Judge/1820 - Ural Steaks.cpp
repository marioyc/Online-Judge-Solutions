#include <cstdio>

using namespace std;

int main(){
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    printf("%d\n",n <= k? 2 : (2*n + k - 1) / k);
    
    return 0;
}
