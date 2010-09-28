#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int T,total,n;
    int a[24];
    int ac,t,cont;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&total,&n);
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        sort(a,a+n);
        
        ac=t=cont=0;
        
        for(int i=0;i<n && t+a[i]<=total; i++){
            ac++;
            cont+=t+a[i];
            t+=a[i];
        }
        
        printf("Scenario #%d:\nSteve wins with %d solved problems and a score of %d.\n\n",caso,ac,cont);
    }
    
    return 0;
}
