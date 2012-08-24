#include <cstdio>
#include <cstring>

using namespace std;

int N,sum[5000];

int main(){
    scanf("%d",&N);
    
    char s[2];
    int a[N];
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        
        if(s[0] == 'B') a[i] = 0;
        else a[i] = 1;
    }
    
    int best = N,K = 1;
    
    for(int k = 1;k <= N;++k){
        int cont = 0,aux = 0;
        
        memset(sum,0,sizeof sum);
        
        for(int i = N - 1;i >= k - 1 && cont < best;--i){
            if((a[i] ^ aux) == 0){
                sum[i + 1 - k] = 1;
                aux ^= 1;
                ++cont;
            }
            
            aux ^= sum[i];
        }
        
        bool ok = true;
        
        for(int i = k - 2;i >= 0 && ok;--i){
            if((a[i] ^ aux) == 0)
                ok = false;
            aux ^= sum[i];
        }
        
        if(ok && cont < best){
            best = cont;
            K = k;
        }
    }
    
    printf("%d %d\n",K,best);
    
    return 0;
}
