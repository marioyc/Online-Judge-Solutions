#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int a,b,c,d,e;
    double B,C,D,E;
    double conv = M_PI / 180;
    
    while(true){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        
        if(a == 0) break;
        
        if(a + b + c + d + e != 180) puts("Impossible");
        else{
            B = b * conv;
            C = c * conv;
            D = d * conv;
            E = e * conv;
            
            double k = sin(C) * sin(D) * sin(B + C + E) / (sin(B) * sin(E) * sin(C + D + E));
            double x = atan(sin(C + E) / (k + cos(C + E)));
            
            printf("%.2f\n",x / conv);
        }
    }
    
    return 0;
}
