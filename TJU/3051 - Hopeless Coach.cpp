#include <cstdio>
#include <algorithm>

using namespace std;

float memo[154][462],win,draw,lose;

float solve(int n, int p){
    if(p<=0) return 100.0;
    if(n==0) return 0.0;
    
    if(memo[n][p]>-0.5) return memo[n][p];
    
    memo[n][p]=win*solve(n-1,p-3)+draw*solve(n-1,p-1)+lose*solve(n-1,p);
    return memo[n][p];
}

int main(){
    int N,P,W,D,L;
    
    while(1){
        scanf("%d %d",&N,&P);
        if(N==0 && P==0) break;
        
        scanf("%d %d %d",&W,&D,&L);
        win=(float)W/(W+D+L);
        draw=(float)D/(W+D+L);
        lose=1-win-draw;
        
        for(int i=N;i>0;i--) fill(memo[i],memo[i]+P+1,-1);
        
        printf("%.1f\n",solve(N,P));
    }
    
    return 0;
}
