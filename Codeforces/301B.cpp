#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool reach[100];
int best[100];

int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    
    int a[n],x[n],y[n];
    a[0] = a[n - 1] = 0;
    
    for(int i = 1;i + 1< n;++i)
        scanf("%d",&a[i]);
    
    for(int i = 0;i < n;++i)
        scanf("%d %d",&x[i],&y[i]);
    
    int lo = 0,hi = 50000000,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        memset(reach,false,sizeof reach);
        reach[0] = true;
        best[0] = mi;
        
        for(int it = 0;it < n;++it){
            for(int i = 0;i < n;++i){
                for(int j = 0;j < n;++j){
                    if(j != i && reach[i]){
                        int aux = best[i] - d * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
                        
                        if(aux >= 0){
                            aux += a[j];
                            
                            if(!reach[j]) best[j] = aux;
                            else best[j] = max(best[j],aux);
                            reach[j] = true;
                        }
                    }
                }
            }
        }
        
        if(reach[n - 1]) hi = mi;
        else lo = mi + 1;
    }
    
    printf("%d\n",lo);
    
    return 0;
}
