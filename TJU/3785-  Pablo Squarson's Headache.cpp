#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,n[200],d[200],x[200],y[200];
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        for(int i = 1;i < N;++i)
            scanf("%d %d",&n[i],&d[i]);
        
        x[0] = y[0] = 0;
        
        for(int i = 1;i < N;++i){
            if(d[i] == 0){
                x[i] = x[ n[i] ] - 1;
                y[i] = y[ n[i] ];
            }
            
            if(d[i] == 1){
                x[i] = x[ n[i] ];
                y[i] = y[ n[i] ] - 1;
            }
            
            if(d[i] == 2){
                x[i] = x[ n[i] ] + 1;
                y[i] = y[ n[i] ];
            }
            
            if(d[i] == 3){
                x[i] = x[ n[i] ];
                y[i] = y[ n[i] ] + 1;
            }
        }
        
        int mnx = x[0],mxx = x[0],mny = y[0],mxy = y[0];
        
        for(int i = 1;i < N;++i){
            mnx = min(mnx,x[i]);
            mxx = max(mxx,x[i]);
            
            mny = min(mny,y[i]);
            mxy = max(mxy,y[i]);
        }
        
        printf("%d %d\n",mxx - mnx + 1,mxy - mny + 1);
    }
    
    return 0;
}
