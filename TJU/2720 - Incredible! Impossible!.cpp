#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MOD 100000000000000000LL

int r[125];
long long memo[126][126][126];

long long solve(int pos, int c1, int c2, int c3){
    if(pos == -1){
        if(c1 || c2 || c3) return 0;
        return 1;
    }
    
    long long &ret = memo[pos][c1][c2];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i <= c1;++i){
            for(int j = max(0,r[pos] - i - c3);j <= c2 && i + j <= r[pos];++j){
                int k = r[pos] - i - j;
                
                ret += solve(pos - 1,c1 - i,c2 - j,c3 - k);
                if(ret >= MOD) ret -= MOD;
            }
        }
    }
    
    return ret;
}

int main(){
    int n,c1,c2,c3;
    
    scanf("%d %d %d %d",&n,&c1,&c2,&c3);
    
    int diff = c1 + c2 + c3;
    
    for(int i = 0;i < n;++i){
        scanf("%d",&r[i]);
        diff -= r[i];
    }
    
    if(diff != 0) printf("0\n");
    else{
        memset(memo,-1,sizeof memo);
        printf("%lld\n",solve(n - 1,c1,c2,c3));
    }
    
    return 0;
}
