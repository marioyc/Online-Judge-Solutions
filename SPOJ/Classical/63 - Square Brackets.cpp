#include <cstdio>
#include <cstring>

using namespace std;

int memo[38][38];
bool open[38];

int solve(int s, int e){
    if(s > e) return 1;
    if(open[e]) return 0;
    if(e == s+1) return 1;
    
    int &ret = memo[s][e];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = s+1;i <= e;i += 2)
            if(!open[i]) ret += solve(s+1,i-1) * solve(i+1,e);
    }
    
    return ret;
}

int main(){
    int T,N,K;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&K);
        
        memset(open,false,sizeof(open));
        
        for(int i = 0,x;i < K;++i){
            scanf("%d",&x);
            open[--x] = true;
        }
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,2*N-1));
    }
    
    return 0;
}
