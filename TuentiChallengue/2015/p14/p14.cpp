#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXV 10000
#define eps 1e-8

struct point{
    double x,y;
    
    point(){}
    point(double _x, double _y) : x(_x), y(_y){}
    
    double cross(point P){
        return x * P.y - y * P.x;
    }

    bool operator < (const point &p) const{
        if(fabs(x-p.x)>eps) return x<p.x;
        return y>p.y;
    }
};

double signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)/2;
}

bool ccw(const point &p1, const point &p2, const point &p3){
    return signed_area(p1,p2,p3)>-eps;
}

bool ccw(const vector<point> &poly){
    //primero hallamos el punto inferior ubicado mas a la derecha
    int ind = 0,n = poly.size();
    double x = poly[0].x,y = poly[0].y;

    for(int i=1;i<n;i++){
        if (poly[i].y>y) continue;
        if (fabs(poly[i].y-y)<eps && poly[i].x<x) continue;
        ind = i;
        x = poly[i].x;
        y = poly[i].y;
    }
    
    if (ind==0) return ccw(poly[n-1],poly[0],poly[1]);
    return ccw(poly[ind-1],poly[ind],poly[(ind+1)%n]);
}

bool isInConvex(vector <point> &A, const point &P){
  int n = A.size(), lo = 1, hi = A.size() - 1;
  
  if(signed_area(A[0], A[1], P) <= 0) return 0;
  if(signed_area(A[n-1], A[0], P) <= 0) return 0;
  
  while(hi - lo > 1){
    int mid = (lo + hi) / 2;
    
    if(signed_area(A[0], A[mid], P) > 0) lo = mid;
    else hi = mid;
  }
  
  return signed_area(A[lo], A[hi], P) > 0;
}

vector<int> L[MAXV];
stack<int> S;
bool in_stack[MAXV];
int low[MAXV],curh,cont_scc,id_scc[MAXV];

void tarjan(int cur){
    S.push(cur);
    in_stack[cur] = true;
    low[cur] = ++curh;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(low[to] == -1){
            tarjan(to);
            low[cur] = min(low[cur],low[to]);
        }else if(in_stack[to]){
            low[cur] = min(low[cur],low[to]);
        }
    }
    
    if(low[cur] == curh){
        int nxt;
        
        do{
            nxt = S.top();
            S.pop();
            in_stack[nxt] = false;
            id_scc[nxt] = cont_scc;
        }while(nxt != cur);
        
        ++cont_scc;
    }
    
    --curh;
}

void build_scc(int V){
    memset(low,-1,sizeof low);
    memset(in_stack,false,sizeof in_stack);
    curh = cont_scc = 0;
    
    for(int i = 0;i < V;++i)
        if(low[i] == -1)
            tarjan(i);
}

point p[MAXV];
vector<point> poly[MAXV];
//vector<int> L2[MAXV];

int main(){
    int E;

    cin >> E;

    for(int i = 0,n;i < E;++i){
        cin >> p[i].x >> p[i].y >> n;

        for(int j = 0,x,y;j < n;++j){
            cin >> x >> y;
            poly[i].push_back(point(x,y));
        }

        if(!ccw(poly[i]))
            reverse(poly[i].begin(),poly[i].end());
    }

    for(int i = 0;i < E;++i){
        for(int j = 0;j < E;++j){
            if(isInConvex(poly[i],p[j])){
                L[i].push_back(j);
            }
        }
    }

    build_scc(E);
    
    bool in[cont_scc];

    memset(in,false,sizeof in);

    for(int i = 0;i < E;++i){
        for(int j = (int)L[i].size() - 1;j >= 0;--j){
            int to = L[i][j];

            if(id_scc[i] != id_scc[to])
                in[ id_scc[to] ] = true;
        }
    }

    int ans = 0;

    for(int i = 0;i < cont_scc;++i)
        if(!in[i])
            ++ans;

    cout << ans << endl;

    return 0;
}