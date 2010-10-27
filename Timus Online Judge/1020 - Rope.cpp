#include <cstdio>
#include <cmath>

using namespace std;

double x[100],y[100];

double border(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    int N;
    double R;
    
    scanf("%d %lf",&N,&R);
    
    for(int i = 0;i<N;++i)
        scanf("%lf %lf",&x[i],&y[i]);
    
    double ans = 2*acos(-1.0)*R+border(N-1,0);
    
    for(int i = 1;i<N;++i)
        ans += border(i-1,i);
    
    printf("%.2lf\n",ans);
    
    return 0;
}
