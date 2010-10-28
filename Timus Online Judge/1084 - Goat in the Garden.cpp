#include <cstdio>
#include <cmath>

using namespace std;

double PI = acos(-1.0);

double solve(int L, int R){
    if(2*R*R>=L*L) return L*L;
    if(2*R<=L) return PI*R*R;
    return L*sqrt(4.0*R*R-L*L)+(PI-4*acos(L/2.0/R))*R*R;
}

int main(){
    int L,R;
    scanf("%d %d",&L,&R);
    
    printf("%.3lf\n",solve(L,R));
    
    return 0;
}
