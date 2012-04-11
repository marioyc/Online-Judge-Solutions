#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000007

int cont[MOD + 1];

int main(){
    int tc = 1,T,K,C,n,a0;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&K,&C,&n,&a0);
        
        memset(cont,0,sizeof cont);
        ++cont[a0];
        
        long long x = a0;
        
        for(int i = 1;i < n;++i){
            x = (K * x + C) % MOD;
            ++cont[x];
        }
        
        for(int i = 1;i <= MOD;++i)
            cont[i] += cont[i - 1];
        
        long long ans = 0;
        
        for(int i = 1;i <= MOD;++i){
            if(cont[i] > cont[i - 1]){
                ans += (long long)i * (cont[i] - cont[i - 1]) * cont[i - 1];
                ans -= (long long)i * (cont[i] - cont[i - 1]) * (cont[MOD] - cont[i]);
            }
        }
        
        printf("Case %d: %lld\n",tc++,ans);
    }
    
    return 0;
}
