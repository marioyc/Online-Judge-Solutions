#include <cstdio>
#include <cstring>

using namespace std;

int L1,L2;
char s1[100001],s2[101];
int nxt[100001][26];

int main(){
    scanf("%s %s",s1,s2);
    L1 = strlen(s1); L2 = strlen(s2);
    
    memset(nxt[L1],-1,sizeof nxt[L1]);
    
    for(int i = L1 - 1;i >= 0;--i){
        for(int j = 0;j < 26;++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][ s1[i] - 'a' ] = i;
    }
    
    long long ans = 0;
    
    for(int i = 0;i <= L1 - L2;++i){
        int pos = i - 1;
        
        for(int j = 0;j < L2;++j){
            ++pos;
            pos = nxt[pos][ s2[j] - 'a' ];
            if(pos == -1) break;
        }
        
        if(pos == -1) break;
        ans += L1 - pos;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
