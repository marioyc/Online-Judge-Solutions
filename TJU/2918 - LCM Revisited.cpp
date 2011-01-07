#include <cstdio>

using namespace std;

int solve(int n){
    int ret = n,phi = 1,div = 1,ans = n;
    
    for(int i = 2;i<=n/i;++i){
        if(n%i==0){
            int exp = 0;
            
            while(n%i==0){
                n /= i;
                ++exp;
                phi *= i;
            }
            
            div *= (exp+1);
            phi -= phi/i;
        }
    }
    
    if(n>1){
        phi *= (n-1);
        div *= 2;
    }
    
    ans -= phi+div;
    return ans+1;
}

int main(){
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("%d\n",solve(n));
    }
    
    return 0;
}
