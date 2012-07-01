#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int xa,ya,xb,yb,n;
    double d,theta,r;
    
    while(true){
        scanf("%d %d %d %d %d",&xa,&ya,&xb,&yb,&n);
        
        if(n == 0) break;
        
        d = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
        theta = M_PI / n * (n / 2);
        
        r = d / 2 / sin(theta);
        
        printf("%.6f\n",n * r * r / 2 * sin(2 * M_PI / n));
    }
    
    return 0;
}
