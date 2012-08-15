#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXL 50000
#define B 31

int L;
char s[MAXL + 1];
unsigned int powB[MAXL + 1];
unsigned int H[MAXL + 1];

void init_hash(){
    H[L] = 0;
    
    for(int i = L - 1;i >= 0;--i)
        H[i] = H[i + 1] * B + s[i] - 'a';
    
    powB[0] = 1;
    
    for(int i = 1;i <= L;++i)
        powB[i] = powB[i - 1] * B;
}

unsigned int get_hash(int pos, int len){
    unsigned int h = H[pos] - powB[len] * H[pos + len];
    return h;
}

int main(){
    int T,dp[MAXL];
    char c[2];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&L);
        
        for(int i = 0;i < L;++i){
            scanf("%s",c);
            s[i] = c[0];
        }
        
        init_hash();
        
        int ans = 1;
        
        for(int len = 1;len <= L / 2;++len){
            for(int i = 0;i + len <= L;){
                int e = i,aux = 0;
                
                while(e + len <= L && get_hash(e,len) == get_hash(i,len)){
                    e += len;
                    ++aux;
                }
                
                int lo1 = 0,hi1 = min(len - 1,i),mi;
                
                while(lo1 < hi1){
                    mi = (lo1 + hi1 + 1) >> 1;
                    
                    if(get_hash(i - mi,mi) == get_hash(i + len - mi,mi)) lo1 = mi;
                    else hi1 = mi - 1;
                }
                
                int lo2 = 0,hi2 = min(len - 1,L - e);
                
                while(lo2 < hi2){
                    mi = (lo2 + hi2 + 1) >> 1;
                    
                    if(get_hash(i,mi) == get_hash(e,mi)) lo2 = mi;
                    else hi2 = mi - 1;
                }
                
                if(lo1 + lo2 >= len) ++aux;
                
                ans = max(ans,aux);
                i = e;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
