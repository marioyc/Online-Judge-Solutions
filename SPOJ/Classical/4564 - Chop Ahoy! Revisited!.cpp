#include <cstdio>
#include <cstring>

using namespace std;

char s[26];
int L,memo[25][226];

int solve(int pos, int prev){
    if(pos == L) return 1;
    
    int &ret = memo[pos][prev];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = pos,cur = 0;i < L;++i){
            cur += s[i] - '0';
            if(cur >= prev) ret += solve(i+1,cur);
        }
    }
    
    return ret;
}

int main(){
    int tc = 1;    
    
    while(true){
        scanf("%s",s);
        if(s[0] == 'b') break;
        
        L = strlen(s);
        
        memset(memo,-1,sizeof(memo));
        printf("%d. %d\n",tc++,solve(0,0));
    }
    
    return 0;
}
