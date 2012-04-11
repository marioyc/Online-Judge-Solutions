#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int tc = 1,T,p,a,b;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&p,&a,&b);
        
        printf("Case %d: ",tc++);
        
        if(2 * a >= p || 2 * b >= p) puts("Eta Shombhob Na.");
        else{
            double c = p / 2.0 - a,d = p / 2.0 - b;
            double S = sqrt(a * b * c * d);
            double r = 2 * S / p;
            
            printf("%.6f\n",r);
        }
    }
    
    return 0;
}
