#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    bool isPrime[32000];
    int P[3432],sz = 0;
    
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i < 32000;++i){
        if(isPrime[i]){
            P[sz++] = i;
            
            if(i <= 178)
                for(int j = i * i;j < 32000;j += i)
                    isPrime[j] = false;
        }
    }
    
    int T,A,B;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&A,&B);
        
        int ans = 1;
        
        if(B % A == 0){
            for(int i = 0;i < sz;++i){
                int aux = 0;
                
                while(A % P[i] == 0){
                    A /= P[i];
                    --aux;
                }
                
                while(B % P[i] == 0){
                    B /= P[i];
                    ++aux;
                }
                
                ans += aux;
            }
            
            if(B / A != 1) ++ans;
        }else ans = 0;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
