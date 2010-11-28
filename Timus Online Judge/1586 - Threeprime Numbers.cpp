#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> L[100];

bool isPrime(int n){
    if(n==2) return true;
    if(n%2==0) return false;
    
    for(int i = 3;i<=n/i;i += 2)
        if(n%i==0) return false;    
    
    return true;
}

long long memo[9999][100],MOD = 1000000009L;

long long solve(int n, int last){
    if(n==0) return 1;
    if(last<10) return 0;
    
    long long &ret = memo[n][last];
    
    if(ret==-1){
        ret = 0;
        
        for(int i = L[last].size()-1;i>=0;--i)
            ret = (ret+solve(n-1,(last*10+L[last][i])%100))%MOD;
    }
    
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 10;i<100;++i)
        for(int j = 0;j<10;++j)
            if(isPrime(i*10+j))
                L[i].push_back(j);
    
    long long ans = 0;
    memset(memo,-1,sizeof(memo));
    
    for(int i = 10;i<100;++i)
        ans = (ans+solve(n-2,i))%MOD;
    
    printf("%lld\n",ans);
    
    return 0;
}
