#include <cstdio>
#include <cstring>

using namespace std;

long long B = 1000000000000000LL;

struct Bignum{
    long long a,b;
    
    Bignum(){}
    
    Bignum(long long _a, long long _b){
        a = _a; b =_b;
    }
    
    Bignum operator + (Bignum X){
        long long x = a + X.a;
        long long y = b + X.b;
        
        x += y / B;
        y %= B;
        
        return Bignum(x,y);
    }
    
    Bignum operator * (int X){
        long long x = a * X;
        long long y = b * X;
        
        x += y / B;
        y %= B;
        
        return Bignum(x,y);
    }
    
    void print(){
        if(a) printf("%lld%.15lld\n",a,b);
        else printf("%lld\n",b);
    }
};

int main(){
    int L;
    char s[27];
    bool used[26];
    
    while(true){
        scanf("%d",&L);
        if(L == 0) break;
        
        scanf("%s",s);
        
        memset(used,false,sizeof used);
        
        Bignum ans = Bignum(0,0);
        
        for(int i = 0;i < L;++i){
            Bignum aux = Bignum(0,1);
            
            for(int j = i + 1;j < L;++j)
                aux = aux * (26 - j);
            
            for(char c = 'A';c < s[i];++c)
                if(!used[c - 'A'])
                    ans = ans + aux;
            
            used[s[i] - 'A'] = true;
        }
        
        ans.print();
    }
    
    return 0;
}
