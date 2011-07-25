#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    double k1,k2,k3;
    
    scanf("%lf %lf %lf",&k1,&k2,&k3);
    
    printf("%.0f\n",1000*k1*k2*k3 / (k1*k2 + k2*k3 + k3*k1));
    
    return 0;
}
