#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double eps = 1e-7;

struct point{
    double x,y;
    
    point(){}
    point(double _x, double _y) : x(_x), y(_y) {}
    
    point operator + (point P){
        return point(x + P.x,y + P.y);
    }
    
    point operator - (point P){
        return point(x - P.x,y - P.y);
    }
    
    point operator * (double t){
        return point(x * t,y * t);
    }
    
    double dot(point P){
        return x * P.x + y * P.y;
    }
    
    double cross(point P){
        return x * P.y - y * P.x;
    }
    
    double dist(point P){
        return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
    }
}s,e,M[5][2];

int n,ind[6];

double area(point a, point b, point c){
    return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

bool cross(point a, point b, point c, point d){
    return area(a,b,c) * area(a,b,d) < eps && area(c,d,a) * area(c,d,b) < eps;
}

point intersection(point a, point b, point c, point d){
    return a + (b - a) * ((c - a).cross(d - c) / (b - a).cross(d - c));
}

point projection(point x, point a, point b){
    return a + (b - a) * ((x - a).dot(b - a) / (b - a).dot(b - a));
}

point reflection(point x, point a, point b){
    return x + (projection(x,a,b) - x) * 2;
}

bool check(int m, point E){
    int prev = -1,cur;
    point S = s;
    
    for(int i = m - 1;i >= 0;--i){
        cur = ind[i];
        
        if(!cross(S,E,M[cur][0],M[cur][1])) return false;
        
        point X = intersection(S,E,M[cur][0],M[cur][1]);
        
        for(int j = 0;j < n;++j)
            if(j != prev && j != cur && cross(S,X,M[j][0],M[j][1]))
                return false;
        
        S = X;
        E = reflection(E,M[cur][0],M[cur][1]);
        prev = cur;
    }
    
    for(int j = 0;j < n;++j)
        if(j != prev && cross(S,E,M[j][0],M[j][1]))
            return false;
    
    return true;
}

double ans;

void dfs(int m, int last){
    if(m == 6) return;
    
    point e2 = e;
    
    for(int i = 0;i < m;++i)
        e2 = reflection(e2,M[ ind[i] ][0],M[ ind[i] ][1]);
    
    if(check(m,e2)) ans = min(ans,s.dist(e2));
    
    for(int i = 0;i < n;++i){
        if(i != last){
            ind[m] = i;
            dfs(m + 1,i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    
    while(true){
        cin >> n;
        
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            cin >> M[i][0].x >> M[i][0].y >> M[i][1].x >> M[i][1].y;
        
        cin >> s.x >> s.y;
        cin >> e.x >> e.y;
        
        ans = 1e15;
        
        dfs(0,-1);
        
        cout << fixed << setprecision(4) << ans << '\n';
    }
    
    return 0;
}
