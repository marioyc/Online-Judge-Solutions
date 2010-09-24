#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int a[N],b[N],x[N];
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]>b[i]) swap(a[i],b[i]);
        x[i]=a[i]+b[i];
    }
    
    sort(x,x+N);
    
    int S=0;
    
    for(int i=0;i<N;i++) S-=b[i];
    for(int i=0;i<N/2;i++) S+=x[i];
    
    printf("%d\n",S);
    
    return 0;
}
