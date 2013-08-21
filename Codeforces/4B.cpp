#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,sum;
    
    scanf("%d %d",&n,&sum);
    
    int mn[n],mx[n];
    int l = 0,r = 0;
    
    for(int i = 0;i < n;++i){
        scanf("%d %d",&mn[i],&mx[i]);
        l += mn[i]; r += mx[i];
    }
    
    if(sum < l || sum > r) printf("NO\n");
    else{
        int a[n];
        
        for(int i = 0;i < n;++i){
            a[i] = mn[i];
            mx[i] -= mn[i];
            sum -= mn[i];
        }
        
        for(int i = 0;i < n;++i){
            int aux = min(sum,mx[i]);
            a[i] += aux;
            sum -= aux;
        }
        
        printf("YES\n");
        for(int i = 0;i < n;++i)
            printf("%d ",a[i]);
        printf("\n");
    }
    
    return 0;
}
