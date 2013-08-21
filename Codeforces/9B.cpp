#include <cstdio>
#include <cmath>

using namespace std;

int vb,vs,xu,yu;
double eps = 1e-8;

double f(int x){
    return (double)x / vb + sqrt((double)(x - xu) * (x - xu) + (double)yu * yu) / vs;
}

int main(){
    int n;
    scanf("%d %d %d",&n,&vb,&vs);
    
    int x[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&x[i]);
    
    scanf("%d %d",&xu,&yu);
    
    int ans = 1;
    
    for(int i = 2;i < n;++i){
        double di = f(x[i]),dans = f(x[ans]);
        
        if((abs(di - dans) < eps && abs(xu - x[i]) < abs(xu - x[ans])) || di < dans)
            ans = i;
    }
    
    printf("%d\n",ans + 1);
    
    return 0;
}
