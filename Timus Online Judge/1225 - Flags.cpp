#include <cstdio>
#include <cstring>

using namespace std;

long long memo[45];

long long solve(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    
    long long &ret = memo[n];
    
    if(ret==-1) ret = solve(n-1)+solve(n-2);
    return ret;
}

int main(){
    int N;
    scanf("%d",&N);
    
    memset(memo,-1,sizeof(memo));
    printf("%lld\n",2*solve(N-1));
    
    return 0;
}
