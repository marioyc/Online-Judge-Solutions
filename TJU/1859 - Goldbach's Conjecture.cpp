#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int MAX_N = (1<<15);
    bool isPrime[MAX_N+1];
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i<=MAX_N;++i){
        if(isPrime[i]){
            if(i<=181)
                for(int j = i*i;j<=MAX_N;j += i)
                    isPrime[j] = false;
        }
    }
    
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        int ans = 0;
        
        for(int i = 2;i<=n/2;++i)
            if(isPrime[i] && isPrime[n-i])
                ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
