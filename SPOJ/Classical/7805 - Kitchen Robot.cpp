#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int W,L,N,x[18],y[18];
double memo[(1<<18)][18];

double minDist(int x1, int y1, int x2, int y2){
    int ret = (x2-(-x1))*(x2-(-x1))+(y2-(y1))*(y2-(y1));
    ret = min(ret,(x2-(x1))*(x2-(x1))+(y2-(-y1))*(y2-(-y1)));
    ret = min(ret,(x2-(2*W-x1))*(x2-(2*W-x1))+(y2-(y1))*(y2-(y1)));
    ret = min(ret,(x2-(x1))*(x2-(x1))+(y2-(2*L-y1))*(y2-(2*L-y1)));
    
    return sqrt(ret);
}

double solve(int mask, int last){
    double &ret = memo[mask][last],aux;
    
    if(ret<-0.5){
        if(mask==(1<<N)-1) ret = min(min(x[last],W-x[last]),min(y[last],L-y[last]));
        else{
            for(int i = 0;i<N;++i){
                if((mask & (1<<i))==0){
                    aux = minDist(x[last],y[last],x[i],y[i])+solve(mask | (1<<i),i);
                    if(ret<-0.5 || aux<ret) ret = aux;
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int T,xs,ys;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&W,&L);
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i)
            scanf("%d %d",&x[i],&y[i]);
        
        scanf("%d %d",&xs,&ys);
        
        for(int i = 0;i<(1<<N);++i)
            for(int j = 0;j<N;++j)
                memo[i][j] = -1;
        
        double ans = sqrt((xs-x[0])*(xs-x[0])+(ys-y[0])*(ys-y[0]))+solve(1,0);
        
        for(int i = 1;i<N;++i)
            ans = fmin(ans,sqrt((xs-x[i])*(xs-x[i])+(ys-y[i])*(ys-y[i]))+solve((1<<i),i));
        
        printf("%.14f\n",ans);
    }
    
    return 0;
}
