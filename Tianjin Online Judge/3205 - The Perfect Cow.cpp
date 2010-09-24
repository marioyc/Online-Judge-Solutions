#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a[N],b[N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) scanf("%d",&a[j]);
        sort(a,a+N);
        b[i]=a[N/2];
    }
    
    sort(b,b+N);
    printf("%d\n",b[N/2]);
    
    return 0;
}
