#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,x[800],y[800];
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i) scanf("%d",&x[i]);
        for(int i=0;i<n;++i) scanf("%d",&y[i]);
        
        sort(x,x+n);
        sort(y,y+n);
        
        long long sum = 0;
        for(int i=0;i<n;++i) sum += (long long)x[i]*y[n-1-i];
        
        printf("Case #%d: %lld\n",tc,sum);
    }
    
    return 0;
}
