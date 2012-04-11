#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000000

int div[MAXN + 1];

int main(){
    memset(div,-1,sizeof div);
    
    for(int i = 2;i <= MAXN;++i){
        if(div[i] == -1){
            div[i] = i;
            
            if(i <= MAXN / i)
                for(int j = i * i;j <= MAXN;j += i)
                    div[j] = i;
        }
    }
    
    int L,U;
    
    scanf("%d %d",&L,&U);
    
    long long num;
    int ans;
    
    for(int i = L;i <= U;++i){
        int aux = i;
        long long sum = 1;
        
        while(aux != 1){
            int p = div[aux],exp = 0;
            long long prod = p;
            
            while(aux % p == 0){
                prod *= p;
                aux /= p;
                ++exp;
            }
            
            sum *= (prod - 1) / (p - 1);
        }
        
        if(i == L || sum * ans < num * i){
            num = sum;
            ans = i;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
