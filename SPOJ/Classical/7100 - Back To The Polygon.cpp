#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    point(int _x, int _y){
        x = _x; y = _y;
    }
};

int signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x);
}

bool ccw(const point &p1, const point &p2, const point &p3){
    return signed_area(p1,p2,p3) > 0;
}

bool ccw(const vector<point> &poly){
    int ind = 0,n = poly.size();
    int x = poly[0].x,y = poly[0].y;

    for(int i = 1;i < n;i++){
        if (poly[i].y > y) continue;
        if (poly[i].y == y && poly[i].x < x) continue;
        ind = i;
        x = poly[i].x;
        y = poly[i].y;
    }
    
    if(ind == 0) return ccw(poly[n-1],poly[0],poly[1]);
    return ccw(poly[ind-1],poly[ind],poly[(ind+1)%n]);
}

int main(){
    int N,X1,Y1,X2,Y2,X3,Y3,ind,cont[500][500];
    map< pair<int,int>, int > id;
    int X[500],Y[500];
    int sz[500],adj[500][2];
    bool done[500];
    
    while(true){
        scanf("%d",&N);
        if(N == -1) break;
        
        memset(cont,0,sizeof(cont));
        id.clear();
        ind = 0;
        
        for(int i = 2;i < N;++i){
            scanf("%d %d %d %d %d %d",&X1,&Y1,&X2,&Y2,&X3,&Y3);
            
            if(id.find(make_pair(X1,Y1)) == id.end()) id[make_pair(X1,Y1)] = ind++;
            if(id.find(make_pair(X2,Y2)) == id.end()) id[make_pair(X2,Y2)] = ind++;
            if(id.find(make_pair(X3,Y3)) == id.end()) id[make_pair(X3,Y3)] = ind++;
            
            int A = id[make_pair(X1,Y1)];
            int B = id[make_pair(X2,Y2)];
            int C = id[make_pair(X3,Y3)];
            
            ++cont[A][B]; ++cont[B][C]; ++cont[C][A];
            ++cont[B][A]; ++cont[C][B]; ++cont[A][C];
        }
        
        for(map < pair<int,int>, int > :: iterator it = id.begin();it != id.end();it++){
            X[it->second] = (it->first).first;
            Y[it->second] = (it->first).second;
        }
        
        memset(sz,0,sizeof(sz));
        
        for(int i = 0;i < N;++i){
            for(int j = i + 1;j < N;++j){
                if(cont[i][j] == 1){
                    adj[i][sz[i]++] = j;
                    adj[j][sz[j]++] = i;
                }
            }
        }
        
        int pos = adj[0][0];
        memset(done,false,sizeof(done));
        done[0] = true;
        
        vector<point> poly;
        poly.push_back(point(X[0],Y[0]));
        
        for(int i = 1;i < N;++i){
            int u = adj[pos][0],v = adj[pos][1];
            poly.push_back(point(X[pos],Y[pos]));
            done[pos] = true;
            
            if(!done[u]) pos = u;
            else pos = v;
        }
        
        if(ccw(poly)) reverse(poly.begin(),poly.end());
        
        int s = 0;
        
        for(int i = 0;i < N;++i)
            if(poly[i].x < poly[s].x || (poly[i].x == poly[s].x && poly[i].y < poly[s].y))
                s = i;
        
        printf("%d %d",poly[s].x,poly[s].y);
        for(int i = s + 1;i < N;++i) printf(" %d %d",poly[i].x,poly[i].y);
        for(int i = 0;i < s;++i) printf(" %d %d",poly[i].x,poly[i].y);
        printf("\n");
    }
    
    return 0;
}
