#include <cstdio>

using namespace std;

int main(){
    int N,m = 3;
    scanf("%d",&N);
    
    int a[N],sz = 1;
    a[0] = 2; N -= 2;
    
    while(N>=m){
        N -= m;
        a[sz] = m;
        ++m; ++sz;
    }
    
    while(N>0){
        for(int i=sz-1;i>=0 && N>0;--i){
            ++a[i];
            --N;
        }
    }
    
    printf("%d",a[0]);
    for(int i=1;i<sz;++i) printf(" %d",a[i]);
    printf("\n");
    
    return 0;
}
