#include <cstdio>
#include <cstring>

using namespace std;

int memo[21][11][156];

int solve(int n, int k, int s){
    if(s < 0 || k < 0) return 0;
    if(n == 0) return ((s == 0 && k == 0)? 1:0);
    
    int &ret = memo[n][k][s];
    
    if(ret == -1){
        ret = solve(n - 1,k,s) + solve(n - 1,k - 1,s - n);
    }
    
    return ret;
}

int main(){
    int n,k,s;
    memset(memo,-1,sizeof memo);
    
    while(true){
        scanf("%d %d %d",&n,&k,&s);
        if(n == 0) break;
        
        printf("%d\n",solve(n,k,s));
    }
    
    return 0;
}
