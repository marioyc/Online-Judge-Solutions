#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,K;
    
    scanf("%d",&T);
    
    char s[100001];
    int sum[100001];
    
    while(T--){
        scanf("%d %d %s",&N,&K,s);
        
        sum[0] = 0;
        
        for(int i = 0;i < N;++i)
            sum[i + 1] = sum[i] + s[i] - '0';
        
        long long a = 0,b = (long long)N * N;
        
        for(int i = 0;i < N;++i){
            if(s[i] == '1'){
                int r = min(i + K,N - 1);
                a += 2 * (sum[r + 1] - sum[i]) - 1;
            }
        }
        
        long long g = __gcd(a,b);
        a /= g;
        b /= g;
        
        printf("%lld/%lld\n",a,b);
    }
    
    return 0;
}
