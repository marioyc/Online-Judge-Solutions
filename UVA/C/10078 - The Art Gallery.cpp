#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct point{
    int x,y;
    
    point(){
    }
    
    point(int _x, int _y){
        x=_x; y=_y;
    }
    
    bool operator < (const point &p) const{
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
};

bool ccw(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)>0;
}

bool convex(const vector<point> &poly){
    int n=poly.size();
    
    for(int i=0;i+2<n;i++)
        if(!ccw(poly[i],poly[i+1],poly[i+2])) return false;
    
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,x,y;
    vector<point> poly,poly2;
    bool used[50];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        poly.clear();
        for(int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            poly.push_back(point(x,y));
        }
        
        sort(poly.begin(),poly.end());
        
        poly2.clear();
        poly2.push_back(poly[0]);
        fill(used,used+N,false);
        used[0]=true;
        
        
        for(int i=0;i+1<N;i++){
            int next;
            for(int j=1;j<N;j++)
                if(!used[j]){
                    next=j;
                    break;
                }
                
            for(int j=1;j<N;j++)
                if(!used[j] && !ccw(poly2[i],poly[next],poly[j])) next=j;
            
            used[next]=true;
            poly2.push_back(poly[next]);
        }
        
        poly2.push_back(poly2[0]);
        poly2.push_back(poly2[1]);
        
        if(convex(poly2)) printf("No\n");
        else printf("Yes\n");
    }
    
    return 0;
}
