#include <cstdio>
#include <cstring>

using namespace std;

int p[430],sz = 0;

void getPrimes(){
    bool isPrime[3001];
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i<=3000;++i){
        if(isPrime[i]){
            p[sz++] = i;
            
            if(i<=54)
                for(int j = i*i;j<=3000;j += i)
                    isPrime[j] = false;
        }
    }
}

int getExp(int x, int n){
    int ret = 0;
    
    while(n>=x){
        ret += n/x;
        n /= x;
    }
    
    return ret;
}

int main(){
    getPrimes();
    
    int n,r;
    
    while(scanf("%d %d",&n,&r)==2){
        printf("%dC%d",n,r);
        
        bool start = true;
        
        for(int i = 0;i<sz;++i){
            int exp = getExp(p[i],n)-getExp(p[i],r)-getExp(p[i],n-r);
            
            for(int j = 0;j<exp;++j){
                printf(" %c %d",start? '=' : '*',p[i]);
                start = false;
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
