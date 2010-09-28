#include<cstdio>
#include<cmath>

using namespace std;

#define L(k) 2*n*sin(a[j]-a[k])

int main(){    
    int T,n;
    int p,q;
    double a[10000];
    double max;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        
        max=0.0;
        
        scanf("%d %d",&p,&q);
        a[0]=M_PI*p/q;
        
        for(int j=1,k=0;j<n;j++){
            scanf("%d %d",&p,&q);
            a[j]=M_PI*p/q;
            
            while(L(k+1)>L(k)) k++;
            
            max=fmax(max,L(k));
        }
        
        printf("Scenario #%d:\n%.2f\n\n",i,max);
    }
    
    return 0;
}
