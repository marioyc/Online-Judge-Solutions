#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,W,H,n,x[100][2],y[100][2],S;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&W,&H);
        scanf("%d",&n);
        
        S = 0;
        
        for(int i = 0;i<n;++i){
            scanf("%d %d %d %d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
            S += (x[i][1]-x[i][0])*(y[i][1]-y[i][0]);
        }
        
        bool ok = true;
        
        for(int i = 0;i<n;++i){
            for(int j = i+1;j<n;++j){
                if(max(x[i][0],x[j][0])<min(x[i][1],x[j][1]) && max(y[i][0],y[j][0])<min(y[i][1],y[j][1]))
                    ok = false;
            }
        }
        
        if(!ok){
            puts("NONDISJOINT");
            continue;
        }
        
        for(int i = 0;i<n;++i)
            if(x[i][0]<0 || x[i][1]>W || y[i][0]<0 || y[i][1]>H)
                ok = false;
        
        if(!ok){
            puts("NONCONTAINED");
            continue;
        }
        
        if(S!=W*H) puts("NONCOVERING");
        else puts("OK");
    }
    
    return 0;
}
