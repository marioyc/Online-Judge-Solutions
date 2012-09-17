#include <cstdio>

using namespace std;

int main(){
    int N,a[10000],sum;
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        sum = 0;
        
        for(int i = 0;i < N;++i)
            sum += a[i];
        
        int ans = -1;
        
        if(sum % N == 0){
            int x = sum / N;
            ans = 1;
            
            for(int i = 0;i < N && a[i] < x;++i)
                ans += x - a[i];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
