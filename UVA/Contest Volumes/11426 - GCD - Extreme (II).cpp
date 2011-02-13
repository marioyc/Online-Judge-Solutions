#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int div[4000001],p,exp;
long long f1[4000001],f2[4000001],aux,pow;

int main(){
    memset(div,-1,sizeof(div));
    
    for(int i = 2;i<=4000000;++i){
        if(div[i]==-1){
            div[i] = i;
            
            if(i<=2000)
                for(int j = i*i;j<=4000000;j += i)
                    div[j] = i;
        }
    }
    
    memset(f2,-1,sizeof(f2));
    f1[1] = 0;
    f2[1] = 1;
    
    for(int i = 2;i<=4000000;++i){
        p = div[i]; exp = 0;
        aux = i; pow = 1;
        
        while(aux%p==0){
            pow *= p;
            ++exp;
            
            aux /= p;
        }
        
        f2[i] = ((exp+1)*pow-exp*(pow/p))*f2[aux];
        f1[i] = f1[i-1]+f2[i]-i;
    }
    
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        printf("%lld\n",f1[N]);
    }
    
    return 0;
}
