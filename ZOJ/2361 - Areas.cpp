#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 80

const double eps = 1e-8;

struct point{
    double x,y;

    point(){}
    point(double _x, double _y):
        x(_x), y(_y){}

    point operator - (point P){
        return point(x - P.x,y - P.y);
    }

    point operator + (point P){
        return point(x + P.x,y + P.y);
    }

    point operator * (double k){
        return point(k * x,k * y);
    }

    point perp(){
        return point(-y,x);
    }

    double dot(point P){
        return x * P.x + y * P.y;
    }

    bool operator < (point P)const{
        if(fabs(x - P.x) < eps) return y < P.y;
        return x < P.x;
    }

    bool operator == (point P)const{
        return fabs(x - P.x) < eps && fabs(y - P.y) < eps;
    }
};

double area(point &a, point &b, point &c){
    return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

struct line{
    point p,v;

    line(){}
    line(point _p, point _v):
        p(_p), v(_v){}
}l[MAXN];

bool intersection(line &a, line &b, point &I){
    if(fabs(b.v.dot(a.v.perp())) < eps) return false;
    I = b.p + b.v * ((a.p - b.p).dot(a.v.perp()) / b.v.dot(a.v.perp()));
    return true;
}

struct edge{
    int to;
    bool used;

    edge(){}
    edge(int _to):
        to(_to), used(false){}
};

int main(){
    int T,n,x1,y1,x2,y2;
    point I;
    map<point, int> id;
    vector<point> intersec[MAXN];
    point p[MAXN * MAXN];
    vector<edge> L[MAXN * MAXN];
    point path[MAXN * MAXN];
    bool first = true;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        for(int i = 0;i < n;++i){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            l[i] = line(point(x1,y1),point(x2 - x1,y2 - y1));
            intersec[i].clear();
        }

        id.clear();
        int m = 0;

        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                if(intersection(l[i],l[j],I)){
                    intersec[i].push_back(I);
                    intersec[j].push_back(I);

                    if(id.find(I) == id.end()){
                        id[I] = m;
                        p[m] = I;
                        ++m;
                    }
                }
            }
        }

        for(int i = 0;i < m;++i)
            L[i].clear();

        for(int i = 0;i < n;++i){
            sort(intersec[i].begin(),intersec[i].end());
            intersec[i].erase(unique(intersec[i].begin(),intersec[i].end()),intersec[i].end());
            
            int sz = intersec[i].size();

            for(int j = 0;j + 1 < sz;++j){
                int u = id[ intersec[i][j] ],v = id[ intersec[i][j + 1] ];
                L[u].push_back(edge(v));
                L[v].push_back(edge(u));
            }
        }

        int ans = 0;
        vector<double> sol;

        for(int i = 0;i < m;++i){
            for(int j = L[i].size() - 1;j >= 0;--j){
                if(!L[i][j].used){
                    int cont = 0;
                    path[cont++] = p[i];
                    path[cont++] = p[ L[i][j].to ];
                    L[i][j].used = true;
                    int cur = id[ path[cont - 1] ];

                    while(true){
                        int to = -1;

                        for(int k = L[cur].size() - 1;k >= 0;--k){
                            if(area(path[cont - 2],path[cont - 1],p[ L[cur][k].to ]) > eps){
                                if(to == -1 || area(path[cont - 1],p[ L[cur][to].to ],p[ L[cur][k].to ]) > eps)
                                    to = k;
                            }
                        }

                        if(to == -1) break;

                        path[cont++] = p[ L[cur][to].to ];
                        L[cur][to].used = true;

                        if(p[ L[cur][to].to ] == path[0]){
                            double aux = 0;
                            
                            for(int k = 0;k + 1 < cont;++k)
                                aux += path[k].x * path[k + 1].y - path[k + 1].x * path[k].y;
                            aux = abs(aux);

                            if(aux > 2*eps){
                                sol.push_back(aux / 2);
                                ++ans;
                            }

                            break;
                        }
                        
                        cur = L[cur][to].to;
                    }
                }
            }
        }

        sort(sol.begin(),sol.end());

        if(!first) printf("\n");
        first = false;
        printf("%d\n",ans);

        for(int i = 0;i < ans;++i)
            printf("%.6f\n",sol[i]);
    }

    return 0;
}
