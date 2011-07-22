#include <cstdio>

using namespace std;

int main(){
    int N,a[1001];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    a[N] = -1;
    
    int cont = 1;
    
    for(int i = 1;i <= N;++i){
        if(a[i] != a[i-1]){
            printf("%d %d ",cont,a[i-1]);
            cont = 1;
        }else ++cont;
    }
    
    return 0;
}
