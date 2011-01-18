#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,S,H,X[50],Y[50],ans_x,ans_y;
    bool is_hatch[41][41];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&S,&H);
        
        memset(is_hatch,false,sizeof(is_hatch));
        
        for(int i = 0;i<H;++i){
            scanf("%d %d",&X[i],&Y[i]);
            is_hatch[X[i]][Y[i]] = true;
        }
        
        bool found = false;
        
        for(int x0 = 0;x0<=S && !found;++x0) for(int y0 = 0;y0<=S && !found;++y0){
            if(!is_hatch[x0][y0]){
                int L2 = 0;
                
                for(int i = 0;i<H;++i)
                    L2 = max(L2,(X[i]-x0)*(X[i]-x0)+(Y[i]-y0)*(Y[i]-y0));
                
                if(x0*x0>=L2 && y0*y0>=L2 && L2 <=(S-y0)*(S-y0) && L2 <=(S-x0)*(S-x0)){
                    found = true;
                    ans_x = x0;
                    ans_y = y0;
                }
            }
        }
        
        if(!found) puts("poodle");
        else printf("%d %d\n",ans_x,ans_y);
    }
    
    return 0;
}
