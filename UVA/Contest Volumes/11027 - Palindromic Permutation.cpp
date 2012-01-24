#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,tc = 1;
    
    scanf("%d",&T);
    
    char s[31],s2[16];
    int K,cont[26];
    
    while(T--){
        scanf("%s %d",s,&K);
        
        int L = strlen(s);
        
        memset(cont,0,sizeof cont);
        
        for(int i = 0;i < L;++i)
            ++cont[s[i] - 'a'];
        
        int odd = 0,ind = -1;
        
        for(int i = 0;i < 26;++i)
            if(cont[i] & 1)
                ++odd, ind = i;
        
        printf("Case %d: ",tc++);
        
        if(odd <= 1){
            char mid;
            
            if(odd == 1) mid = 'a' + ind;
            
            for(int i = 0;i < 26;++i) cont[i] >>= 1;
            
            int sum = L / 2;
            
            long long total = 1;
            
            for(int i = 1;i <= sum;++i) total *= i;
            
            for(int i = 0;i < 26;++i){
                for(int j = 1;j <= cont[i];++j)
                    total /= j;
            }
            
            if(total < K) puts("XXX");
            else{
                for(int i = 0;i < sum;++i){
                    for(int j = 0;j < 26;++j){
                        if(cont[j] != 0){
                            long long aux = 1;
                            
                            for(int k = 1;k <= sum - i - 1;++k) aux *= k;
                            
                            for(int k = 0;k < 26;++k){
                                for(int l = 1;l <= cont[k] - (k == j? 1 : 0);++l)
                                    aux /= l;
                            }
                            
                            if(K <= aux){
                                --cont[j];
                                s2[i] = 'a' + j;
                                break;
                            }else K -= aux;
                        }
                    }
                }
                
                for(int i = 0;i < L / 2;++i) putchar(s2[i]);
                if(odd) putchar(mid);
                for(int i = 0;i < L / 2;++i) putchar(s2[L / 2 - 1 - i]);
                putchar('\n');
            }
        }else puts("XXX");
    }
    
    return 0;
}
