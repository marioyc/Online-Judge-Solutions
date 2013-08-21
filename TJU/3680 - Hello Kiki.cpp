#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

void ext_gcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        ext_gcd(b,a % b,x,y);
        long long tmp = y;
        y = x - a / b * y;
        x = tmp;
    }
}

long long CRT(long long r1, long long m1, long long r2, long long m2){
    long long y1,y2;
    ext_gcd(m1,m2,y1,y2);
    
    long long m = m1 * m2;
    long long ret = (r1 * m2 % m * y2 + r2 * m1 % m * y1) % m;
    if(ret < 0) ret += m;
    return ret;
}

int main(){
    int T,N,rem[6],mod[6];
    int nf,p[19],e[19];
    int rem2[19],mod2[19];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&mod[i]);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&rem[i]);
        
        p[0] = 1; e[0] = 1;
        nf = 1;
        
        for(int i = 0;i < N;++i){
            int aux = mod[i];
            
            for(int j = 2;j <= aux;++j){
                if(aux % j == 0){
                    int cont = 0;
                    
                    while(aux % j == 0){
                        aux /= j;
                        ++cont;
                    }
                    
                    bool found = false;
                    
                    for(int k = 0;k < nf;++k){
                        if(p[k] == j){
                            e[k] = max(e[k],cont);
                            found = true;
                        }
                    }
                    
                    if(!found){
                        p[nf] = j;
                        e[nf] = cont;
                        ++nf;
                    }
                }
            }
        }
        
        for(int i = 0;i < nf;++i){
            int aux = 1;
            
            for(int j = e[i] - 1;j >= 0;--j)
                aux *= p[i];
            
            mod2[i] = aux;
            
            for(int j = 0;j < N;++j)
                if(mod[j] % aux == 0)
                    rem2[i] = rem[j] % aux;
        }
        
        long long R = rem2[0],M = mod2[0];
        
        for(int i = 1;i < nf;++i){
            R = CRT(R,M,rem2[i],mod2[i]);
            M *= mod2[i];
        }
        
        if(R == 0) R += M;
        
        for(int i = 0;i < N;++i)
            if(R % mod[i] != rem[i])
                R = -1;
        
        printf("Case %d: %lld\n",tc,R);
    }
    
    return 0;
}
