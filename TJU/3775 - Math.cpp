#include <cstdio>
#include <cmath>

using namespace std;

double f(double x){
    x  = sqrt(1+1.0/x);
    return -2*x+log((x+1)/(x-1));
}

int main(){
    int s,t;
    
    while(scanf("%d %d",&s,&t)==2)
        printf("%.2f\n",f(t)-f(s));
    
    return 0;
}
