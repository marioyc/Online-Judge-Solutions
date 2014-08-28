#include <cstdio>
#include <cstring>

using namespace std;

int s,a[50],b[50];
long long memo[50][51][51];

long long solve(int pos, int have, int marble){
    if(have < 0) return 0;
    
    if(pos == -1){
        if(have > 0 || marble != s) return 0;
        return 1;
    }
    
    long long &ret = memo[pos][have][marble];
    
    if(ret == -1){
        ret = solve(pos - 1,have,marble);
        
        if(marble == a[pos]) ret += solve(pos - 1,have - 1,b[pos]);
        else if(marble == b[pos]) ret += solve(pos - 1,have - 1,a[pos]);
        else ret += solve(pos - 1,have - 1,marble);
    }
    
    return ret;
}

int main(){
    int T,n,m,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&n,&m,&k,&s);
        
        for(int i = 0;i < m;++i)
            scanf("%d %d",&a[i],&b[i]);
        
        int ans = 1;
        long long aux = 0;
        memset(memo,-1,sizeof memo);
        
        for(int i = 1;i <= n;++i){
            long long ret = solve(m - 1,k,i);
            
            if(ret > aux){
                aux = ret;
                ans = i;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
