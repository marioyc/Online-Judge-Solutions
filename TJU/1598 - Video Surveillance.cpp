#include <cstdio>
#include <algorithm>

using namespace std;

#define INF (1 << 30)

bool ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) > 0;
}

int main(){
    int tc = 1,n;
    int x[100],y[100];
    
    while(true){
        scanf("%d",&n);
        if(n == 0)break;
        
        for(int i = 0;i < n;++i)
            scanf("%d %d",&x[i],&y[i]);
        
        int minx = -INF,maxx = INF,miny = -INF,maxy = INF;
        
        for(int i = 0;i < n;++i){
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            
            if(ccw(x[i],y[i],x[j],y[j],x[k],y[k])){
                if(x[i] == x[j]){
                    if(y[i] > y[j]){
                        maxx = min(maxx,x[j]);
                        maxy = min(maxy,y[j]);
                    }else{
                        minx = max(minx,x[j]);
                        miny = max(miny,y[j]);
                    }
                }else{
                    if(x[i] > x[j]){
                        maxx = min(maxx,x[j]);
                        miny = max(miny,y[j]);
                    }else{
                        minx = max(minx,x[j]);
                        maxy = min(maxy,y[j]);
                    }
                }
            }
        }
        
        printf("Floor #%d\n",tc++);
        
        if(minx <= maxx && miny <= maxy) printf("Surveillance is possible.\n");
        else printf("Surveillance is impossible.\n");
        
        printf("\n");
    }
    
    return 0;
}
