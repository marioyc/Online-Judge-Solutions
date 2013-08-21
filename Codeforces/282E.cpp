#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100005

long long a[MAXN],pref[MAXN],suf[MAXN];
int trie[40 * MAXN][2],cont = 0;

void add(long long x){
    int pos = 0;
    
    for(int i = 39;i >= 0;--i){
        int b = (x >> i & 1);
        if(trie[pos][b] == 0) trie[pos][b] = cont++;
        pos = trie[pos][b];
    }
}

long long solve(long long x){
    int pos = 0;
    long long ret = 0;
    
    for(int i = 39;i >= 0;--i){
        int b = ((x >> i & 1) ^ 1);
        if(trie[pos][b] == 0) b ^= 1;
        else ret ^= (1LL << i);
        pos = trie[pos][b];
    }
    
    return ret;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%I64d",&a[i]);
    
    pref[0] = 0;
    
    for(int i = 0;i < n;++i)
        pref[i + 1] = pref[i] ^ a[i];
    
    suf[n] = 0;
    
    for(int i = n - 1;i >= 0;--i)
        suf[i] = suf[i + 1] ^ a[i];
    
    long long ans = 0;
    
    for(int i = n;i >= 0;--i){
        add(suf[i]);
        ans = max(ans,solve(pref[i]));
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
