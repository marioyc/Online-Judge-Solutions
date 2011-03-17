#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int L,p[78498],cont[78498],sz = 0,freq[26];
char s[1000001];
bool isPrime[1000001];

int get_exp(int n, int p){
    int ret = 0;
    
    while(n != 0){
        ret += n/p;
        n /= p;
    }
    
    return ret;
}

int pow(int a, int b){
    int ret = 1;
    a %= 10;
    
    while(b){
        if(b & 1) ret = ret*a % 10;
        a = a*a % 10;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i<=1000000;++i){
        if(isPrime[i]){
            p[sz] = i;
            ++sz;
            
            if(i<=1000)
                for(int j = i*i;j<=1000000;j += i)
                    isPrime[j] = false;
        }
    }
    
    while(scanf("%s",s)==1){
        L = strlen(s);
        
        memset(freq,0,sizeof(freq));
        
        for(int i = 0;i<L;++i)
            ++freq[s[i]-'a'];
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<78498;++i){
            cont[i] += get_exp(L,p[i]);
            for(int j = 0;j<26;++j) cont[i] -= get_exp(freq[j],p[i]);
        }
        
        int tmp = min(cont[0],cont[2]);
        cont[0] -= tmp;
        cont[2] -= tmp;
        
        int ans = 1;
        
        for(int i = 0;i<78498;++i)
            ans = ans*pow(p[i],cont[i]) % 10;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
