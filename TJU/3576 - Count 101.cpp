#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 9997;
int memo[9999][4];

int solve(int n, int prev){
    if(n==0) return 1;
    
    int &ret = memo[n][prev];
    
    if(ret==-1){
        ret = solve(n-1,(prev<<1) & 3);
        if(prev!=2) ret = (ret+solve(n-1,((prev<<1) | 1) & 3))%MOD;
    }
    
    return ret;
}

int main(){
    int N;
    memset(memo,-1,sizeof(memo));
    
    while(true){
        scanf("%d",&N);
        if(N==-1) break;
        
        if(N==1) puts("2");
        else if(N==2) puts("4");
        else{
            int ans = 0;
            
            for(int i = 0;i<4;++i)
                ans = (ans+solve(N-2,i))%MOD;
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
