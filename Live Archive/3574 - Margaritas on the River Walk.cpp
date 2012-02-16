#include <cstdio>
#include <cstring>

using namespace std;

int N,val[30],memo[30][31][1000];

int solve(int pos, int unused, int have){
    if(pos == N){
        if(unused == N || (unused < N && val[unused] > have)) return 1;
        return 0;
    }
    
    int &ret = memo[pos][unused][have];
    
    if(ret == -1){
        ret = 0;
        
        if(val[pos] <= have) ret = solve(pos + 1,unused,have - val[pos]);
        ret += solve(pos + 1,(unused == N || val[pos] < val[unused])? pos : unused,have);
    }
    
    return ret;
}

int main(){
    int T,have;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&N,&have);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&val[i]);
        
        bool cant = true;
        
        for(int i = 0;i < N;++i)
            if(val[i] <= have)
                cant = false;
        
        memset(memo,-1,sizeof memo);
        
        printf("%d %d\n",tc,cant? 0 : solve(0,N,have));
    }
    
    return 0;
}
