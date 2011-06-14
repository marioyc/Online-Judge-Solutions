#include <cstdio>
#include <algorithm>

using namespace std;

struct rectangle{
    int xl,xr,yl,yr;
    
    rectangle(){}
    
    rectangle(int _xl, int _xr, int _yl, int _yr){
        xl = _xl; xr = _xr; yl = _yl; yr = _yr;
    }
    
    void intersect(rectangle R){
        xl = max(xl,R.xl);
        xr = min(xr,R.xr);
        yl = max(yl,R.yl);
        yr = min(yr,R.yr);
    }
};

int main(){
    int N;
    scanf("%d",&N);
    
    rectangle R(0,100000,0,100000);
    bool valid = true;
    
    for(int i = 0,xl,xr,yl,yr;i < N && valid;++i){
        scanf("%d %d %d %d",&xl,&yl,&xr,&yr);
        
        R.intersect(rectangle(xl,xr,yl,yr));
        
        if(R.xl >= R.xr || R.yl >= R.yr) valid = false;
    }
    
    long long ans = valid? (long long)(R.xr - R.xl) * (R.yr - R.yl) : 0;
    
    printf("%lld\n",ans);
    
    return 0;
}
