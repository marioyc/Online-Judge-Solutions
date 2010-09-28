#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int MOD;

long long pow(int a, int n){
    if(n==0) return 1L;
    
    long long aux = pow(a,n/2);
    
    aux = (aux*aux)%MOD;
    if(n&1) aux = (aux*a)%MOD;
    
    return aux;
}

int main(){
    int B,N,m;
    long long aux,b,ans;
    map<int,int> exp;
    map<int,int>::iterator it;
    
    while(scanf("%d %d %d",&MOD,&B,&N)==3){
        m = (int)ceil(sqrt(MOD));
        
        exp.clear();
        aux = 1;
        
        for(int i=0;i<m;++i){
            exp[aux] = i;
            aux = (aux*B)%MOD;
        }
        
        ans = -1;
        b = pow(B,MOD-m-1); // B ^ (-m)
        aux = N; // N * B ^ (-mi)
        
        // L = i*m+j; 0<=i,j<m
        // B ^ j = N ^ ((-m)*i)
        
        for(int i=0,j;i<m;++i){
            it = exp.find(aux);
            
            if(it!=exp.end()){
                j = exp[aux];
                ans = (long long)i*m+j;
                break;
            }
            
            aux = (aux*b)%MOD;
        }
        
        if(ans!=-1) printf("%lld\n",ans);
        else printf("no solution\n");
    }
    
    return 0;
}
