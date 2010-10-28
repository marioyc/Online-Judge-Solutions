#include <cstdio>
#include <cstring>

using namespace std;

int K;
long long memo[16][2];

long long count(int n, int zeros){
    if(zeros==2) return 0;
    if(n==1) return (zeros==1? K-1 : K);
    
    long long &ret = memo[n][zeros];
    
    if(ret==-1){
        ret = (zeros==1? 0 : count(n-1,1));
        ret += (K-1)*count(n-1,0);
    }
    
    return ret;
}

int main(){
    int N;
    scanf("%d %d",&N,&K);
    
    memset(memo,-1,sizeof(memo));
    long long ans = (K-1)*count(N-1,0);
    
    printf("%lld\n",ans);
    
    return 0;
}
