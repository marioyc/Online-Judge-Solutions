#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int best = 0,ans = 0;
        
        for(int i = 1;i <= N;){
            int k = N / i;
            int curA = (N + 1 + k) / (k + 1);
            
            if(N - k * curA >= best){
                best = N - k * curA;
                if(k) ans = curA;
                else ans = N / k;
            }
            
            i = N / k + 1;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
