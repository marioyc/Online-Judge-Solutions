#include <cstdio>
#include <cmath>

using namespace std;

int phi(int n){
    int ret = 1;
    
    for(int i = 2;i<=n/i;++i){
        if(n%i==0){
            int x = 1;
            
            while(n%i==0){
                x *= i;
                n /= i;
            }
            
            ret *= (x-x/i);
        }
    }
    
    if(n>1) ret *= n-1;
    
    return ret;
}

int pow(int a, long long b, int m){
    if(m==1) return 0;
    if(b==0) return 1;
    if(a==0) return 0;
    
    long long ret = pow(a,b/2,m);
    ret = (ret*ret)%m;
    
    if(b & 1) ret = (ret*a)%m;
    
    return ret;
}

int smallPow(int a, long long b){
    if(a==0) return (b==0? 1 : 0);
    if(b==0) return 1;
    
    int ret = smallPow(a,b/2);
    ret = (ret*ret);
    
    if(b & 1) ret = (ret*a);
    
    return ret;
}

// f(n) >= x
bool check(int n, int x){
    if(n==0) return 1>=x;
    
    int a = n%10,b = n/10;
    
    if(a==1) return 1>=x;
    if(a==0){
        int cont = 0;
        while(b%10==0){
            b /= 10;
            ++cont;
        }
        
        return (cont & 1? 1 : 0)>=x;
    }
    return check(b,(int)ceil(log(x)/log(a)));
}

int f(int x){
    if(x==0) return 1;
    int a = x%10,b = x/10;
    
    if(a==1) return 1;
    
    if(a==0){
        int cont = 0;
        
        while(b%10==0){
            b /= 10;
            ++cont;
        }
        
        return (cont & 1? 1 : 0);
    }
    
    return smallPow(a,f(b));
}

int solve(int n, int m){
    if(m==1) return 0;
    if(n==0) return 1;
    
    int a = n%10, b = n/10;
    
    if(a==0){
        int cont = 0;
        
        while(b%10==0){
            b /= 10;
            ++cont;
        }
        
        return (cont & 1? 1 : 0);
    }
    
    if(check(b,m)){
        int p = phi(m);
        long long x = solve(b,p);
        x = ((x-m)%p+p)%p;
        return pow(a,x+m,m)%m;
    }
    
    return pow(a,f(b),m);
}

int main(){
    int T,n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        printf("%d\n",solve(n,m));
    }
    
    return 0;
}
