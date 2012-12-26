#include <cstdio>

using namespace std;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        long long ans = 0;
        int X,Y;
        
        for(int i = 2;i <= n / i;++i){
            int k = n / (i * i);
            int y = k * i * i;
            int x = k * (i - 1) * (i - 1);
            
            if((long long)x * y > ans){
                ans = (long long)x * y;
                X = x;
                Y = y;
            }
        }
        
        printf("%d*%d\n",X,Y);
    }
    
    return 0;
}
