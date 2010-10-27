#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    printf("%d\n",N>0? N*(N+1)/2 : 1+N*(1-N)/2);
    
    return 0;
}
