#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 2000

struct point{
    int px,py,id;
    
    point(){}
    
    point(int _py, int _px){
        py = _py; px = _px;
    }
    
    bool operator < (point P)const{
        if(py!=P.py) return py<P.py;
        return px<P.px;
    }
};

int N;
point P[MAX_N];
set<point> box;

bool compare_x(point a, point b){ return a.px<b.px; }

inline double dist(point a, point b){
    return	sqrt((long long)(a.px-b.px)*(a.px-b.px)+(long long)(a.py-b.py)*(a.py-b.py));
}

void closest_pair(){
    sort(P,P+N,compare_x);
	
    double ret = dist(P[0],P[1]),aux;
    int id1 = P[0].id,id2 = P[1].id;
    box.insert(P[0]);
	
    set<point> :: iterator it;
	
    for(int i = 1,left = 0;i<N;++i){
        while(left<i && P[i].px-P[left].px>ret) box.erase(P[left++]);
        for(it = box.lower_bound(point((int)floor(P[i].py-ret),(int)floor(P[i].px-ret)));
            it!=box.end() && P[i].py+ret>=(*it).py;++it){
                aux = dist(P[i],*it);
                
                if(aux<ret){
                    ret = aux;
                    id1 = (*it).id;
                    id2 = P[i].id;
                }
        }
        box.insert(P[i]);
    }
	
    printf("%d %d\n",min(id1,id2),max(id1,id2));
}

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i){
        scanf("%d %d",&P[i].px,&P[i].py);
        P[i].id = i+1;
    }
    
    closest_pair();
    
    return 0;
}
