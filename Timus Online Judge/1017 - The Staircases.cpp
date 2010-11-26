#include <cstdio>
#include <cstring>

using namespace std;

long long memo[501][501];

long long solve(int n, int m){
    if(n==0) return 1;
    if(m==0) return 0;
    
    long long &ret = memo[n][m];
    
    if(ret==-1) ret = (n>=m? solve(n-m,m-1) : 0)+solve(n,m-1);
    return ret;
}

int main(){
    int N;
    scanf("%d",&N);
    
    memset(memo,-1,sizeof(memo));
    printf("%lld\n",solve(N,N-1));
    
    return 0;
}
