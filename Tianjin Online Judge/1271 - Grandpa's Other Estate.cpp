#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int t,n,r,ans,cont;    
    int x[100];
    int y[100];
    int x0,y0;
    
    scanf("%d",&t);
    
    for(int sc=1;sc<=t;sc++){
        scanf("%d %d",&n,&r);
        
        for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
        
        ans=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                x0=min(x[i],x[j]);
                y0=min(y[i],y[j]);
                
                cont=0;
                
                for(int k=0;k<n;k++)
                    if(x[k]>=x0 && x[k]<=x0+r && y[k]>=y0 && y[k]<=y0+r) cont++;
                
                ans=max(ans,cont);
            }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
