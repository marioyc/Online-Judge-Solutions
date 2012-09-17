#include <cstdio>
#include <cstring>

using namespace std;

int nd,d[20];
unsigned long long memo[20][2][2];

unsigned long long solve2(int pos, int eq, int one){
    if(pos == -1) return 1;
    
    unsigned long long &ret = memo[pos][eq][one];
    
    if(ret == -1){
        int lim = (eq? d[pos] : 9);
        ret = 0;
        
        for(int i = 0;i <= lim;++i){
            if(i != 4 && !(one && i == 3))
                ret += solve2(pos - 1,i != d[pos]? 0 : eq,i == 1? 1 : 0);
        }
    }
    
    return ret;
}

unsigned long long solve(unsigned long long N){
    nd = 0;
    
    while(N > 0){
        d[nd++] = N % 10;
        N /= 10;
    }
    
    d[nd++] = 0;
    
    memset(memo,-1,sizeof memo);
    return solve2(nd - 1,1,0) - 1;
}

int main(){
    long long N;
    
    while(scanf("%lld",&N) == 1){
        unsigned long long lo = 1,hi = 0,mi;
        
        for(int i = 0;i < 64;++i) hi |= (1ULL << i);
        
        while(lo < hi){
            mi = lo + (hi - lo) / 2;
            
            unsigned long long ret = solve(mi);
            
            if(ret < N) lo = mi + 1;
            else if(ret == N) hi = mi;
            else hi = mi - 1;
        }
        
        printf("%llu\n",lo);
    }
    
    return 0;
}
