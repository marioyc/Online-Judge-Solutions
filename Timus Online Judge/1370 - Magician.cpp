#include <cstdio>

using namespace std;

int main(){
    int N,M,d[1000];
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&d[i]);
    
    for(int i = 0;i < 10;++i)
        printf("%d",d[(M + i) % N]);
    
    printf("\n");
    
    return 0;
}
