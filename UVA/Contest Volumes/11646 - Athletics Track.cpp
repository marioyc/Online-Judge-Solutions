#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int tc=1,a,b;
    double k;
    
    while(scanf("%d : %d",&a,&b)==2){
        k=200/(sqrt(a*a+b*b)*atan((double)b/a)+a);
        printf("Case %d: %.10f %.10f\n",tc++,k*a,k*b);
    }
    
    return 0;
}
