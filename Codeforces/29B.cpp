#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int l,d,v,g,r;
    
    scanf("%d %d %d %d %d",&l,&d,&v,&g,&r);
    
    double ans = 0;
    
    int k = d / (v * (g + r));
    
    if(d < (k * (r + g) + g) * v) ans += (double)d / v;
    else ans += (k + 1) * (r + g);
    
    ans += (double)(l - d) / v;
    
    printf("%.10f\n",ans);
    
    return 0;
}
