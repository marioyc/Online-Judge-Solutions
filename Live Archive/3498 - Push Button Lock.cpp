#include <cstdio>

using namespace std;

int fact[12];

long long solve(int n, long long aux){
    long long ret = aux / fact[n];
    
    for(int i = 1;i <= n;++i)
        ret += solve(n - i,aux / fact[i]);
    
    return ret;
}

int main(){
    fact[0] = 1;
    
    for(int i = 1;i <= 11;++i)
        fact[i] = fact[i - 1] * i;
    
    int T,B;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&B);
        
        printf("%d %d %lld\n",tc,B,solve(B,fact[B]) - 1);
    }
    
    return 0;
}
