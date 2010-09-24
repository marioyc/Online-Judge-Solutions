#include <cstdio>
#include <cstring>

using namespace std;

int memo[101][101];

int solve(int last, int rem){
    if(rem==0) return 1;
    if(memo[last][rem]!=-1) return memo[last][rem];
    int aux = 0;
    
    for(int i=last+1;i<=rem;++i) aux += solve(i,rem-i);
    
    memo[last][rem] = aux;
    return aux;
}

int main(){
    int n,ans[101];
    
    ans[1] = ans[2] = 0;
    
    for(int i=3;i<=100;++i){
        memset(memo,-1,sizeof(memo));
        ans[i] = solve(0,i)-1;
    }
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("%d\n",ans[n]);
    }
    
    return 0;
}
