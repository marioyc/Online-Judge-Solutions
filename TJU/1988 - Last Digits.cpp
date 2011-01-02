#include <cstdio>
#include <cmath>

using namespace std;

int B;

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
    if(b==0) return 1;
    
    long long ret = pow(a,b/2,m);
    ret = (ret*ret)%m;
    
    if(b & 1) ret = (ret*a)%m;
    
    return ret;
}

int smallPow(int a, long long b){
    if(b==0) return 1;
    
    int ret = smallPow(a,b/2);
    ret = (ret*ret);
    
    if(b & 1) ret = (ret*a);
    
    return ret;
}

// f(n) >= x
bool check(int n, int x){
    if(n==0) return 1>=x;
    
    int ceil_log = 0;
    
    double tmp = x;
    
    while(tmp>1+1e-9){
        tmp /= B;
        ++ceil_log;
    }
    
    return check(n-1,ceil_log);
}

int calc(int x){
    if(x==0) return 1;
    return smallPow(B,calc(x-1));
}

int solve(int n, int m){
    if(m==1) return 0;
    if(n==0) return 1;
    
    if(check(n-1,m)){
        int p = phi(m);
        long long x = solve(n-1,p);
        return pow(B,x+p,m);
    }
    
    return pow(B,calc(n-1),m);
}

void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch(c){
            case '-' :
                sign = -1;
                found = true;
                break;
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

int main(){
    int b,x,n,res;
    char ans[101][101][8];
    
    for(int b = 1;b<=100;++b){
        B = b;
        
        for(int i = 1;i<=100;++i){
            if(b>1) res = solve(i,10000000);
            else res = 1;
            
            sprintf(ans[b][i],"%07d",res);
        }
    }
    
    while(true){
        readInt(b);
        if(b==0) break;
        
        readInt(x); readInt(n);
        
        for(int i = n-1;i>=0;--i) putchar(ans[b][x][6-i]);
        putchar('\n');
    }
    
    return 0;
}
