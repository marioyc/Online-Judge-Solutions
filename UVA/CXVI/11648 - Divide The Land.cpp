#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T,a,b,c,d;
    double x,y;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        x=(2*a*c-c*sqrt(2*(a*a+b*b)))/2/(a-b);
        y=x*d/c;
        printf("Land #%d: %.6f %.6f\n",tc,x,y);
    }
    
    return 0;
}
