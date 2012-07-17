#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N,x[301],y[301];

double get_r(double X, double Y){
    double ret = 0;
    
    for(int i = 0;i < N;++i)
        ret = max(ret,(X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
    
    return ret;
}

double searchY(double X){
    double lo = 0,hi = 1000;
    
    for(int it = 0;it < 30;++it){
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;
        
        double ra = get_r(X,a);
        double rb = get_r(X,b);
        
        if(ra < rb) hi = b;
        else lo = a;
    }
    
    return get_r(X,lo);
}

double searchX(){
    double lo = 0,hi = 1000;
    
    for(int it = 0;it < 30;++it){
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;
        
        double ra = searchY(a);
        double rb = searchY(b);
        
        if(ra < rb) hi = b;
        else lo = a;
    }
    
    return searchY(lo);
}

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d %d",&x[i],&y[i]);
    
    printf("%.2f\n",sqrt(searchX()) * 2);
    
    return 0;
}
