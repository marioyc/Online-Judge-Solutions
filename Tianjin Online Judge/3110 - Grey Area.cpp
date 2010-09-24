#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int n,w,v,m,h;
    int a[11];
    double total;
    
    while(1){
        scanf("%d %d",&n,&w);
        if(n==0 && w==0) break;
        
        for(int i=0;i<11;i++) a[i]=0;
        
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            for(int j=0;j<11;j++)
                if(v>=j*w && v<(j+1)*w){
                    a[j]++;
                    break;
                }
        }
        
        for(int i=0;i<11;i++) if(a[i]!=0) m=i;
        
        h=0;
        for(int i=0;i<11;i++) h=max(h,a[i]);
        
        total=0.01;
        for(int i=0;i<m;i++) total+=a[i]*(m-i)*1.0/(h*m);
        
        printf("%.16f\n",total);
    }
    
    return 0;
}
