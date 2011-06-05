#include <cstdio>
#include <cmath>

using namespace std;

double eps = 1e-9,PI = acos(-1.0);

struct point{
    double x,y;
    
    point(){}
    
    point(double _x, double _y){
        x = _x; y = _y;
    }
    
    point operator - (point p){
        return point(x - p.x, y - p.y);
    }
    
    double abs(){
        return sqrt(x * x + y * y);
    }
}P[1000];

double maxi(double x, double y){
    if(x < y) return y;
    return x;
}

double mini(double x, double y){
    if(x < y) return x;
    return y;
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%lf %lf",&P[i].x,&P[i].y);
    
    double maxR[1000];
    
    for(int i = 0;i < n;++i){
        maxR[i] = 50;
        
        for(int j = 0;j < n;++j){
            if(j == i) continue;
            
            double D = (P[j] - P[i]).abs();
            if(D < maxR[i]) maxR[i] = D;
        }
    }
    
    double ans = 0;
    
    for(int i = 0;i < n;++i){
        if(maxR[i] + eps >= 1){
            for(int j = i + 1;j < n;++j){
                if(j == i || maxR[j] + eps < 1) continue;
                
                double D = (P[j] - P[i]).abs();
                
                if(D + eps >= maxR[i] + maxR[j]) ans = maxi(ans,PI * (maxR[i] * maxR[i] + maxR[j] * maxR[j]));
                else{
                    double rmin = maxi(1.0, maxi(D - 50, D - maxR[j]));
                    double rmax = mini(50.0, mini(D - 1, maxR[i]));
                    
                    if(rmax - rmin >= -eps)
                        ans = maxi(ans, PI * maxi(rmin * rmin + (D - rmin) * (D - rmin), rmax * rmax + (D - rmax) * (D - rmax)));
                }
            }
        }
    }
    
    printf("%.4f\n",ans);
    
    return 0;
}
