#include <cstdio>
#include <cstring>

using namespace std;

#define MAXL 705
#define MOD 1000000007

int L;
char s[MAXL];
int close[MAXL],aux[MAXL],sz = 0;
int memo[700][700][3][3];

bool check(int x, int y){
    if(x == 0 || y == 0) return true;
    if(x == y) return false;
    return true;
}

int solve(int l, int r, int cl, int cr){
    if(l > r) return 1;
    
    int &ret = memo[l][r][cl][cr];
    
    if(ret == -1){
        ret = 0;
        
        int e = close[l];
        
        if(e != r || check(1,cr))
            ret = (ret + (long long)solve(l + 1,e - 1,0,1) * solve(e + 1,r,1,cr)) % MOD;
        
        if(e != r || check(2,cr))
            ret = (ret + (long long)solve(l + 1,e - 1,0,2) * solve(e + 1,r,1,cr)) % MOD;
        
        if(check(cl,1))
            ret = (ret + (long long)solve(l + 1,e - 1,1,0) * solve(e + 1,r,0,cr)) % MOD;
        
        if(check(cl,2))
            ret = (ret + (long long)solve(l + 1,e - 1,2,0) * solve(e + 1,r,0,cr)) % MOD;
    }
    
    return ret;
}

int main(){
    scanf("%s",s);
    L = strlen(s);
    
    memset(close,-1,sizeof close);
    
    for(int i = 0;i < L;++i){
        if(s[i] == '(') aux[sz++] = i;
        else{
            close[ aux[sz - 1] ] = i;
            --sz;
        }
    }
    
    memset(memo,-1,sizeof memo);
    printf("%d\n",solve(0,L - 1,0,0));
    
    return 0;
}
