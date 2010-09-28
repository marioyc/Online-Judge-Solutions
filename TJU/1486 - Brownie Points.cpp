#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,x[200000],y[200000],sc1,sc2;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
        
        swap(x[0],x[n/2]);
        swap(y[0],y[n/2]);
        
        sc1=sc2=0;
        
        for(int i=1;i<n;i++){
            if((x[i]>x[0] && y[i]>y[0]) || (x[i]<x[0] && y[i]<y[0])) sc1++;
            else if((x[i]<x[0] && y[i]>y[0]) || (x[i]>x[0] && y[i]<y[0])) sc2++;
        }
        
        printf("%d %d\n",sc1,sc2);
    }
    
    return 0;
}
