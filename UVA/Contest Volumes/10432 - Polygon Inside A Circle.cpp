#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double r; int n;
    
    while(scanf("%lf %d",&r,&n)==2) printf("%.3f\n",n*r*r/2*sin(2*M_PI/n));
    
    return 0;
}
