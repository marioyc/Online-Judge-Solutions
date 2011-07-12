#include <cstdio>

using namespace std;

int main(){
    int T,a[5];
    
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0;i < 4;++i)
            scanf("%d",&a[i]);
        
        int r = a[1] - a[0];
        
        if(a[2] - a[1] == r && a[3] - a[2] == r) a[4] = a[3] + r;
        else a[4] = a[3] * (a[2] / a[1]);
        
        for(int i = 0;i < 5;++i){
            printf("%d",a[i]);
            
            if(i == 4) putchar('\n');
            else putchar(' ');
        }
    }
    
    return 0;
}
