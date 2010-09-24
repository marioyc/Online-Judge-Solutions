#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int tc=1,n,m;
    double x1[100],x2[100],y1[100],y2[100],x[200];
    double ymin,ymax;
    const double eps=1e-8;
    double ans;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%lf %lf %lf %lf",&x1[i],&y1[i],&x2[i],&y2[i]);
        
        for(int i=0;i<n;i++) x[i]=x1[i];
        for(int i=2*n-1;i>=n;i--) x[i]=x2[i-n];
        
        sort(x,x+2*n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(x1[i]>x1[j]){
                    swap(x1[i],x1[j]);
                    swap(x2[i],x2[j]);
                    swap(y1[i],y1[j]);
                    swap(y2[i],y2[j]);
                }
            }
        }
        
        m=2*n;
        ans=0.0;
        for(int i=0;i+1<m;i++){
            ymin=ymax=0;
            for(int j=0;j<n;j++){
                if(x[i]>=x1[j] && x[i+1]<=x2[j]){
                    if(y1[j]>ymax){
                        ans+=(x[i+1]-x[i])*(ymax-ymin);
                        ymin=y1[j];
                        ymax=y2[j];
                    }else ymax>?=y2[j];
                }
            }
            
            ans+=(x[i+1]-x[i])*(ymax-ymin);
        }
        
        printf("Test case #%d\n",tc++);
        printf("Total explored area: %.2f\n\n",ans);
    }
    
    return 0;
}
