#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000
#define MAXL 1000
#define B 31
#define MOD 1000000009

char s[MAXN][MAXL + 1],q[MAXL + 1];
int L[MAXN],prior[MAXN];
long long hash[MAXN][MAXL];

int main(){
    int N,Q;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%s %d",s[i],&prior[i]);
        
        L[i] = strlen(s[i]);
        
        long long h = 0;
        
        for(int j = 0;j < L[i];++j){
            h = (h * B + s[i][j]) % MOD;
            hash[i][j] = h;
        }
    }
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%s",q);
        
        int Lq = strlen(q);
        
        long long h = 0;
        
        for(int i = 0;i < Lq;++i)
            h = (h * B + q[i]) % MOD;
        
        int ans = -1;
        
        for(int i = 0;i < N;++i)
            if(Lq <= L[i] && hash[i][Lq - 1] == h && (ans == -1 || prior[ans] < prior[i]))
                ans = i;
        
        puts(ans == -1? "NO" : s[ans]);
    }
    
    return 0;
}
