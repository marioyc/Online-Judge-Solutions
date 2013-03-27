#include <cstdio>

using namespace std;

#define MAXN 50000
#define NUMB 30
#define MOD 1000000007

int trie[MAXN * NUMB][2],nodes = 1;
int cont[MAXN * NUMB],cont1[MAXN * NUMB][NUMB];

void insert(int a){
    int pos = 0;
    
    for(int i = 29;i >= 0;--i){
        int b = (a >> i & 1);
        
        if(trie[pos][b] == 0) trie[pos][b] = nodes++;
        
        pos = trie[pos][b];
        ++cont[pos];
        
        for(int j = 29;j >= 0;--j)
            if(a >> j & 1) ++cont1[pos][j];
    }
}

int a[MAXN];

int main(){
    int n;
    long long m;
    
    scanf("%d %I64d",&n,&m);
    
    for(int i = 0;i < n;++i){
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    
    int lo = 0,hi = (1 << 30) - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        long long total = 0;
        
        for(int i = 0;i < n;++i){
            int aux = (mi ^ a[i]),pos = 0;
            
            for(int j = 29;j >= 0;--j){
                int opp = (~a[i] >> j & 1);
                
                if((mi >> j & 1) == 0 && trie[pos][opp])
                    total += cont[ trie[pos][opp] ];
                
                int b = (aux >> j & 1);
                
                if(trie[pos][b]) pos = trie[pos][b];
                else break;
            }
        }
        
        if(total < 2*m) hi = mi - 1;
        else lo = mi;
    }
    
    long long ans = 0;
    long long total = 0;
    
    for(int i = 0;i < n;++i){
        int aux = (lo ^ a[i]),pos = 0;
        
        for(int j = 29;j >= 0;--j){
            int opp = (~a[i] >> j & 1);
                
            if((lo >> j & 1) == 0 && trie[pos][opp]){
                total += cont[ trie[pos][opp] ];
                long long sum = 0;
                
                for(int k = 29;k >= 0;--k){
                    if(a[i] >> k & 1) sum = sum * 2 + cont[ trie[pos][opp] ] - cont1[ trie[pos][opp] ][k];
                    else sum = sum * 2 + cont1[ trie[pos][opp] ][k];
                }
                
                ans += sum;
            }
            
            int b = (aux >> j & 1);
            
            if(trie[pos][b]) pos = trie[pos][b];
            else break;
        }
    }
    
    ans /= 2;
    total /= 2;
    
    if(total > m)
        ans -= (long long)(total - m) * (lo + 1);
    
    printf("%I64d\n",ans % MOD);
    
    return 0;
}
