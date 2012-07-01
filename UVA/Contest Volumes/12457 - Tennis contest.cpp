#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T,n;
    double p;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %lf",&n,&p);
        
        double ans = 0;
        
        for(int i = n;i <= 2*n - 1;++i){
            double aux = pow(1 - p,i - n);
            
            for(int j = 0;j < n - 1;++j){
                aux *= (i - 1 - j);
                aux /= (1 + j);
            }
            
            ans += aux;
        }
        
        ans *= pow(p,n);
        
        printf("%.2f\n",ans);
    }
    
    return 0;
}
