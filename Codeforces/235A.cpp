#include <cstdio>
#include <algorithm>

using namespace std;

void strip(int &a, int b){
    int g = __gcd(a,b);
    a /= g;
}

long long f(int a, int b, int c){
    strip(c,b); strip(c,a);
    strip(b,a);
    
    return (long long)a * b * c;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    if(n == 1) printf("1\n");
    else if(n == 2) printf("2\n");
    else if(n % 2 == 1) printf("%I64d\n",(long long)n * (n - 1) * (n - 2));
    else{
        long long ans = 1;
        
        for(int i = max(1,n - 100);i < n ;++i)
            for(int j = i + 1;j < n;++j)
                for(int k = j + 1;k <= n;++k)
                    ans = max(ans,f(i,j,k));
        
        printf("%I64d\n",ans);
    }
    
    return 0;
}
