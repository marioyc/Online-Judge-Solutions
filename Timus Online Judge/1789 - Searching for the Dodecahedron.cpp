#include <cstdio>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    printf("%d\n",2*n - 1);
    
    for(int i = 1;i <= n;++i) printf("%d ",i);
    for(int i = n;i >= 2;--i) printf("%d ",i);
    
    return 0;
}
