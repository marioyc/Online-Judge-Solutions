#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
double X[50][2],Y[50][2];

double calc_dist(){
    double ret = 20000,x1,y1,x2,y2;
    
    for(int i = 0;i<N;++i) for(int j = i+1;j<N;++j){
        x1 = max(X[i][0],X[j][0]); x2 = min(X[i][1],X[j][1]);
        y1 = max(Y[i][0],Y[j][0]); y2 = min(Y[i][1],Y[j][1]);
        
        if(x1<x2 && y1<y2) return 0;
        
        if(x1<x2) ret = min(ret,min(abs(Y[i][0]-Y[j][1]),abs(Y[j][0]-Y[i][1])));
        if(y1<y2) ret = min(ret,min(abs(X[i][0]-X[j][1]),abs(X[j][0]-X[i][1])));
        
        for(int k1 = 0;k1<4;++k1) for(int k2 = 0;k2<4;++k2){
            ret = min(ret,sqrt((X[j][k2 & 1]-X[i][k1 & 1])*(X[j][k2 & 1]-X[i][k1 & 1])
                            +(Y[j][k2 >> 1]-Y[i][k1 >> 1])*(Y[j][k2 >> 1]-Y[i][k1 >> 1])));
        }
    }
    
    return ret;
}

int main(){
    int tc = 1,T,r,d;
    int x[50][2],y[50][2];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i)
            scanf("%d %d %d %d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
        
        scanf("%d %d",&r,&d);
        
        double lo = 0,hi = 5000,mi;
        
        for(int it = 0;it<50;++it){
            mi = (lo+hi)/2;
            
            for(int i = 0;i<N;++i){
                X[i][0] = x[i][0]-r*mi;
                X[i][1] = x[i][1]+r*mi;
                Y[i][0] = y[i][0]-r*mi;
                Y[i][1] = y[i][1]+r*mi;
            }
            
            if(calc_dist()<d) hi = mi;
            else lo = mi;
        }
        
        printf("Case %d: %.3f\n",tc++,lo+1e-11);
    }
    
    return 0;
}
