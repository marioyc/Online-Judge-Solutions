#include <cstdio>

using namespace std;

int main(){
    int K;
    scanf("%d",&K);
    
    int ans = 0;
    
    for(int i = 1;i<=K/i;++i){
        if(K%i==0){
            if(i>=3){
                ans = i-1;
                break;
            }
            
            if(K/i>=3) ans = K/i-1;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
} 
