#include <cstdio>
#include <cstring>

using namespace std;

long long memo[201][200];

long long solve(int n, int have){
    if(n == 0){
        if(have) return 0;
        return 1;
    }
    
    long long &ret = memo[n][have];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i * n <= have;++i)
            ret += solve(n - 1,have - i * n);
    }
    
    return ret;
}

int main(){
    int N,K;
    
    memset(memo,-1,sizeof memo);
    
    while(true){
        scanf("%d %d",&N,&K);
        if(N == 0) break;
        
        N -= K;
        
        printf("%lld\n",solve(K,N));
    }
    
    return 0;
}
