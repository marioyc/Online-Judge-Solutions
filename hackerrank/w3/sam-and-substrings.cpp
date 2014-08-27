#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define MAXL 200000

int num_dig(int n){
    int ret = 0;
    
    while(n){
        n /= 10;
        ++ret;
    }
    
    return ret;
}

char s[MAXL + 1];

int main(){
    scanf("%s",s);
    int d = strlen(s);
    
    long long ans = 0,aux = 0;
    
    for(int i = d - 1;i >= 0;--i){
        aux = (aux * 10 + 1) % MOD;
        ans = (ans + (s[i] - '0') * (i + 1) * aux) % MOD;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
