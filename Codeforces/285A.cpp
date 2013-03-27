#include <cstdio>

using namespace std;

int main(){
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    for(int i = 0;i < k;++i)
        printf("%d ",n - i);
    for(int i = k;i < n;++i)
        printf("%d ",i - (k - 1));
    printf("\n");
    
    return 0;
}
