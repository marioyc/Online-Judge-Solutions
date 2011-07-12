#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int dp[7994][4];
    
    for(int i = 0;i < 7994;++i) dp[i][1] = 1;
    dp[0][2] = dp[0][3] = 1;
    
    for(int k = 2;k <= 3;++k){
        for(int i = 1;i < 7994;++i){
            dp[i][k] = dp[i][k-1];
            if(i >= k) dp[i][k] += dp[i-k][k];
        }
    }
    
    bool is_prime[7994];
    memset(is_prime,true,sizeof(is_prime));
    
    for(int i = 2;i < 7994;++i){
        if(is_prime[i]){
            for(int j = i*i;j < 7994;j += i)
                is_prime[j] = false;
        }
    }
    
    bool is_square[7994];
    
    memset(is_square,false,sizeof(is_square));
    for(int i = 1;i*i < 7994;++i) is_square[i*i] = true;
    
    int sp2[501];
    sp2[1] = 2;
    
    for(int i = 3,n = 2;i < 7994;i += 2){
        if(is_prime[i]){
            bool check = false;
            
            for(int j = 1;2*j*j <= i && !check;++j)
                if(is_square[i-j*j]) check = true;
            
            if(check) sp2[n++] = i;
        }
    }
    
    int T,n,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[sp2[n]][k]);
    }
    
    return 0;
}
