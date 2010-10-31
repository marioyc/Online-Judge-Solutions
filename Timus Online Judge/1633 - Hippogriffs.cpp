#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    long long a1,b1,a2,b2;
    scanf("%lld %lld %lld %lld",&a1,&b1,&a2,&b2);
    
    long double c = (long double)(b1*b1+b2*b2-a1*a1-a2*a2)/(2*a1*b1+2*a2*b2);
    long double x = -c+sqrt(c*c+1);
    long double f = a1*a1+a2*a2+((2*a1*b1+2*a2*b2)*x+(b1*b1+b2*b2-a1*a1-a2*a2))/(x*x+1);
    
    long double ans = max((long double)(b1*b1+b2*b2),(long double)(a1*a1+a2*a2));
    
    ans = max(ans,f);
    
    c = (long double)(a1*a1+a2*a2-b1*b1-b2*b2)/(2*a1*b1+2*a2*b2);
    x = -c+sqrt(c*c+1);
    f = b1*b1+b2*b2+((2*a1*b1+2*a2*b2)*x+(a1*a1+a2*a2-b1*b1-b2*b2))/(x*x+1);
    
    ans = max(ans,f);
    
    printf("%.18Lf\n",sqrt(ans));
    
    return 0;
}
