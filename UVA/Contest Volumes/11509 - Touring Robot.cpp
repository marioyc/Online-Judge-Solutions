#include <cstdio>
#include <cmath>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    point(int _x, int _y){
        x = _x; y = _y;
    }
    
    point operator - (const point &p) const{
        return point(x-p.x,y-p.y);
    }
    
    double dot(const point &p) const{
        return x*p.x+y*p.y;
    }
    
    double abs2() const{
        return dot(*this);
    }
    
    double abs() const{
        return sqrt(abs2());
    }
};

// angulo entre dos vectores
double get_angle(point P1, point P2){
    double sina = P1.y / P1.abs(),cosa = P1.x / P1.abs();
    double sinb = P2.y / P2.abs(),cosb = P2.x / P2.abs();
    double sinc = sinb * cosa - sina * cosb;
    double cosc = cosb * cosa + sina * sinb;
    
    double x = atan2(sinc,cosc);
    if(x < 0) x += 2 * M_PI;
    
    return x;
}

int main(){
    int N;
    point P[1000];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d %d",&P[i].x,&P[i].y);
        
        double total = 0;
        
        for(int i = 0;i < N;++i)
            total += get_angle(P[(i+1) % N] - P[i],P[(i+2) % N] - P[(i+1) % N]);
        
        printf("%.0f\n",total / (2 * M_PI));
    }
    
    return 0;
}
