#include <cstdio>
#include <algorithm>

using namespace std;

bool found[1000001];

int main(){    
    int N,G,n;
    int a[300];
    
    scanf("%d",&N);
    
    for(int tc=1;tc<=N;tc++){
        scanf("%d",&G);
        
        for(int i=0;i<G;i++) scanf("%d",&a[i]);
        
        fill(found,found+1000001,false);
        
        for(int i=0;i<G;i++)
            for(int j=i+1;j<G;j++){
                if(a[i]>a[j]) n=a[i]-a[j];
                else n=a[j]-a[i];
                
                for(int k=1;k*k<=n;k++)
                    if(n%k==0)
                        found[k]=found[n/k]=true;
            }
        
        for(int i=1;i<=1000000;i++)
            if(!found[i]){
                printf("%d\n",i);
                break;
            }
    }    
    
    return 0;
}
