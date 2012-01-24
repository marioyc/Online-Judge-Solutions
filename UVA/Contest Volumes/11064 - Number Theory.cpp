#include <cstdio>

using namespace std;

int main(){
    int n,phi,div,ans;
    
    while(scanf("%d",&n) == 1){
        phi = div = 1;
        ans = n;
        
        for(int i = 2;i <= n / i;++i){
            if(n % i == 0){
                int exp = 0,aux = 1;
                
                while(n % i == 0){
                    n /= i;
                    aux *= i;
                    ++exp;
                }
                
                div *= (exp + 1);
                phi *= (aux - aux / i);
            }
        }
        
        if(n != 1){
            div *= 2;
            phi *= n - 1;
        }
        
        printf("%d\n",ans - phi - div + 1);
    }
    
    return 0;
}
