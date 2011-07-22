#include <cstdio>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int a[50],sz = 0,m;
    
    while(n != 1){
        a[sz++] = n / 2;
        n = (n+1) / 2;
    }
    
    printf("%d\n",sz);
    
    for(int i = 0;i < sz;++i)
        printf("%d ",a[i]);
    
    return 0;
}
