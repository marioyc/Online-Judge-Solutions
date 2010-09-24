#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double eps=1e-9;

struct point{
    double x,y;
    
    point(){
    }
    
    point(const double _x, const double _y){
        x=_x; y=_y;
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
    
    point u() const{
    	return point(x/abs(),y/abs());
    }
};

bool PolygonsAreSimilar(const vector<point> &P1, const vector<point> &P2){
	int n=P1.size()-1;
	point a[n],b[n];
	
	for(int i=0;i<n;i++) a[i]=P1[i+1]-P1[i];
	for(int i=0;i<n;i++) b[i]=P2[i+1]-P2[i];
	
	for(int i=1;i<n;i++)
		if(a[0].abs2()*b[i].abs2()!=b[0].abs2()*a[i].abs2())
			return false;
	
	for(int i=0;i<n;i++) a[i]=a[i].u();
	for(int i=0;i<n;i++) b[i]=b[i].u();
	
	for(int i=0;i<n;i++){
		double aux=a[i].dot(b[0]),aux2;
		
		bool found=true;
		
		for(int j=1;j<n;j++){
			aux2=a[(i+j)%n].dot(b[j]),aux2;
			if(fabs(aux-aux2)>eps){
				found=false;
				break;
			}
		}
		
		if(found) return true;
	}
	
	return false;
}

int main(){
	int n,x,y;
	vector<point> P1,P2;
	
	while(scanf("%d",&n)==1){
		P1.clear(); P2.clear();
		
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			P1.push_back(point(x,y));
		}
		
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			P2.push_back(point(x,y));
		}
		
		if(PolygonsAreSimilar(P1,P2)) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
