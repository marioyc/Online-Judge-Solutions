#include <cstdio>

using namespace std;

int exp(int p, int &n){
    int ans = 0;
    
    while(n%p==0){
        n /= p;
        ++ans;
    }
    
    return ans;
}

const int MOD = 201004;

long long pow(int a, int b){
    if(b==0) return 1;
    
    int aux = 1;
    if(b&1) aux = a;
    
    long long aux2 = pow(a,b/2);
    aux = ((aux2*aux2)%MOD * aux)%MOD;
    
    return aux;
}

int main(){
    int n,m,x;
    long long ans;
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        ans = 1;
        
        if(n%2==0){
            x = exp(2,n)*m;
            ans = pow(2,x-1);
        }
        
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                x = exp(i,n)*m;
                ans = ((ans*pow(i,x-1))%MOD * (i-1))%MOD;
            }
        }
        
        if(n>1){
            x = m;
            ans = ((ans*pow(n,x-1))%MOD * (n-1))%MOD;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
