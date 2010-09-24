#include <cstdio>

using namespace std;

#define min(x,y) (x)<(y)? (x):(y)
#define max(x,y) (x)>(y)? (x):(y)

int main(){
    int n,x[1000],y[1000],z[1000],d[1000];
    int xl,xh,yl,yh,zl,zh,ans;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;++i) scanf("%d %d %d %d",&x[i],&y[i],&z[i],&d[i]);
        
        xl = x[0]; xh = x[0]+d[0];
        yl = y[0]; yh = y[0]+d[0];
        zl = z[0]; zh = z[0]+d[0];
        ans = -1;
        
        for(int i=1;i<n;++i){
            xl = max(xl,x[i]);
            xh = min(xh,x[i]+d[i]);
            yl = max(yl,y[i]);
            yh = min(yh,y[i]+d[i]);
            zl = max(zl,z[i]);
            zh = min(zh,z[i]+d[i]);
            
            if(xl>=xh || yl>=yh || zl>=zh){
                ans = 0;
                break;
            }
        }
        
        if(ans==-1) ans = (xh-xl)*(yh-yl)*(zh-zl);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
