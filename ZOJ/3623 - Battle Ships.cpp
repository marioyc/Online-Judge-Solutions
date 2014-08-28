#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,L,t[30],l[30];
int memo[331][331];

int solve(int curL, int totall){
    if(totall < 0) return 0;
    if(totall >= curL) return 1;
    
    int &ret = memo[curL][totall];
    
    if(ret == -1){
        ret = totall == 0? 660 : (curL + totall - 1) / totall;
        
        for(int i = 0;i < N;++i)
            ret = min(ret,t[i] + solve(curL - totall * t[i],totall + l[i]));
    }
    
    return ret;
}

int main(){
    while(scanf("%d %d",&N,&L) == 2){
        for(int i = 0;i < N;++i)
            scanf("%d %d",&t[i],&l[i]);
        
        memset(memo,-1,sizeof memo);
        
        printf("%d\n",solve(L,0));
    }
    
    return 0;
}
