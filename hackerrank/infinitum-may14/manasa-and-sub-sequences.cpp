#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

char s[200001];

int main(){
    scanf("%s",s);
    int L = strlen(s);
    
    long long ans = 0,p2 = 1;
    
    for(int i = 0;i < L;++i){
        ans = (ans * 11 + (s[i] - '0') * p2) % MOD;
        p2 <<= 1;
        if(p2 >= MOD) p2 -= MOD;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
