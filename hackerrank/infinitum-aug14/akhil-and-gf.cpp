#include <cstdio>
#include <map>

using namespace std;

int M;

pair<long long,long long> solve(long long n){
    if(n == 1) return make_pair(1,10 % M);
    
    pair<long long,long long> aux = solve(n / 2);
    pair<long long,long long> ret;
    ret.second = aux.second * aux.second % M;
    ret.first = (aux.first * aux.second + aux.first) % M;
    
    if(n & 1){
        ret.second = (ret.second * 10) % M;
        ret.first = (ret.first * 10 + 1) % M;
    }
    
    return ret;
}

int main(){
    int T;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %d",&N,&M);
        pair<long long,long long> ret = solve(N);
        printf("%lld\n",ret.first);
    }
    
    return 0;
}
