#include <cstdio>
#include <cmath>

using namespace std;

double eps = 1e-8;

int solve(double P, double Q){
    for(int x = 1;;++x){
        int y = (int)ceil(P*x);
        if(y-eps>P*x && y+eps<Q*x) return x;
        if(y+1-eps>P*x && y+1+eps<Q*x) return x;
    }
    
    return -1;
}

int main(){
    double P,Q;
    scanf("%lf %lf",&P,&Q);
    
    printf("%d\n",solve(P/100,Q/100));
    
    return 0;
}
