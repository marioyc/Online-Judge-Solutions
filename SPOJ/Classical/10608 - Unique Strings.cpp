#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXL 65

long long memo[MAXL][7][7][7];
long long cont[MAXL + 1];

long long solve(int pos, int mn, int mx, int cur){
    if(mx - mn > 3) return 0;
    if(pos == -1) return 1;
    
    long long &ret = memo[pos][mn + 3][mx + 3][cur];
    
    if(ret == -1){
        ret = solve(pos - 1,min(mn,cur - 1),mx,cur - 1) + solve(pos - 1,mn,max(mx,cur + 1),cur + 1);
    }
    
    return ret;
}

int main(){
    memset(memo,-1,sizeof memo);
    
    for(int i = 1;i <= MAXL;++i)
        cont[i] = solve(i - 1,0,0,0);
    
    long long N;
    
    scanf("%lld",&N);
    
    int len = 1;
    
    while(cont[len] < N){
        N -= cont[len];
        ++len;
    }
    
    int pos = len - 1,mn = 0,mx = 0,cur = 0;
    
    while(pos >= 0){
        long long aux = solve(pos - 1,min(mn,cur - 1),mx,cur - 1);
        
        if(aux < N){
            putchar('b');
            N -= aux;
            mx = max(mx,cur + 1);
            ++cur;
        }else{
            putchar('a');
            mn = min(mn,cur - 1);
            --cur;
        }
        
        --pos;
    }
    
    putchar('\n');
    
    return 0;
}
