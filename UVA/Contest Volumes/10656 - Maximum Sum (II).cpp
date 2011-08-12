#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,pos,zero,a[1000];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        pos = zero = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&a[i]);
            if(a[i] > 0) pos++;
            if(a[i] == 0) zero++;
        }
        
        if(pos > 0){
            bool first = true;
            
            for(int i = 0;i < N;++i){
                if(a[i] > 0){
                    if(!first) printf(" ");
                    first = false;
                    printf("%d",a[i]);
                }
            }
            
            printf("\n");
        }else if(zero > 0) printf("0\n");
        else{
            int mx = a[0];
            
            for(int i = 1;i < N;++i)
                mx = max(mx,a[i]);
            
            printf("%d\n",mx);
        }
    }
    
    return 0;
}
