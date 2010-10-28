#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,Q;
    scanf("%d",&N);
    
    int a[100000];
    for(int i = 0;i<N;++i)
        scanf("%d",&a[i]);
    
    sort(a,a+N);
    
    scanf("%*[\n #]%d",&Q);
    
    for(int i = 0,x;i<Q;++i){
        scanf("%d",&x);
        printf("%d\n",a[x-1]);
    }
    
    return 0;
}
