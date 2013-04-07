#include <cstdio>

int n,a[100];

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    int q,x,y;
    
    scanf("%d",&q);
    
    while(q--){
        scanf("%d %d",&x,&y);
        --x;
        
        if(x) a[x - 1] += y - 1;
        if(x + 1 < n) a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    
    for(int i = 0;i < n;++i)
        printf("%d\n",a[i]);
    
    return 0;
}
