#include <cstdio>
#include <cstring>

using namespace std;

int L;
char s[20];
long long memo[19][192][2];

long long solve(int pos, int S, int eq){
    if(pos == L) return (S == 0? 1 : 0);
    
    long long &ret = memo[pos][S][eq];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i <= 9;++i){
            if(eq == 1 || (eq == 0 && i <= s[pos]-'0'))
                ret += solve(pos + 1,S - i,(i < s[pos]-'0')? 1 : eq);
        }
    }
    
    return ret;
}

int main(){
    int S;
    long long A,B;
    
    scanf("%lld %lld %d",&A,&B,&S);
    
    sprintf(s,"%lld",B);
    L = strlen(s);
    
    memset(memo,-1,sizeof(memo));
    long long ans = solve(0,S,0);
    
    if(A > 0){
        sprintf(s,"%lld",A-1);
        L = strlen(s);
        memset(memo,-1,sizeof(memo));
        ans -= solve(0,S,0);
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
