#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    double m,b,x,y,eps = 1e-8;
    int n,ans = 0;
    
    scanf("%lf %lf %d",&m,&b,&n);
    
    for(int i = 0;i < n;++i){
        scanf("%lf %lf",&x,&y);
        
        if(x > -eps && abs(y - m*x - b) < eps)
            ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
