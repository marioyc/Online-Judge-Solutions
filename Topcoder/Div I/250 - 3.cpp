#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double eps = 1e-9;

class ConvexPolygons
{
public:
	struct point{
		double x,y;
		
		point(){}
		
		point(double _x, double _y){
			x = _x; y = _y;
		}
		
		point operator + (const point &p) const{
			return point(x+p.x,y+p.y);
		}
		
		point operator - (const point &p) const{
			return point(x-p.x,y-p.y);
		}
		
		point operator * (double t) const{
			return point(t*x,t*y);
		}
		
		point perp(){
			return point(-y,x);
		}
		
		double dot(const point &p) const{
			return x*p.x+y*p.y;
		}
		
		bool operator < (const point &p) const{
			if(fabs(x-p.x)>eps) return x<p.x;
			return y>p.y;
		}
	};
	
	struct line{
		point p1,p2;
		
		line(){}
		
		line(point _p1, point _p2){
			p1 = _p1; p2 = _p2;
		}
	};
	
	bool lineIntersection(line L1, line L2, point &I){
		point n = (L2.p2-L2.p1).perp();
		
		double denom = n.dot(L1.p2-L1.p1);
		if(fabs(denom)<eps) return false;
		double t = n.dot(L2.p1-L1.p1)/denom;
		
		I = L1.p1 + (L1.p2-L1.p1)*t;
		return true;
	}
	
	double signed_area2(const point &p1, const point &p2, const point &p3){
		return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x));
	}
	
	bool ccw(const point &p1, const point &p2, const point &p3){
		return signed_area2(p1,p2,p3)>-eps;
	}
	
	bool ccw(const vector<point> &poly){
		int ind = 0, n = poly.size();
		double x = poly[0].x, y = poly[0].y;
		
		for(int i=1;i<n;++i){
			if(poly[i].y>y) continue;
			if(fabs(poly[i].y-y)<eps && poly[i].x<x) continue;
			ind = i;
			x = poly[i].x;
			y = poly[i].y;
		}
		
		if(ind==0) return ccw(poly[n-1],poly[0],poly[1]);
		return ccw(poly[ind-1],poly[ind],poly[(ind+1)%n]);
	}
	
	bool PointInsideConvexPolygon(const point &P, vector<point> &poly){
		int n = poly.size();
		
		for(int i=1;i<=n;++i)
			if(!ccw(poly[i-1],poly[i%n],P))
				return false;
		
		return true;
	}
	
	vector<point> ConvexHull(vector<point> P){
		sort(P.begin(),P.end());
		
		int n = P.size(), k = 0;
		point H[2*n];
		
		for(int i=0;i<n;++i){
			while(k>=2 && !ccw(H[k-2],H[k-1],P[i])) --k;
			H[k++] = P[i];
		}
		
		for(int i=n-2,t=k;i>=0;--i){
			while(k>t && !ccw(H[k-2],H[k-1],P[i])) --k;
			H[k++] = P[i];
		}
		
		return vector<point> (H,H+k);
	}
	
	double signed_area(const vector<point> &poly){
		int n = poly.size();
		if(n<3) return 0.0;
		
		double S = 0.0;
		
		for(int i=1;i<=n;++i)
			S += poly[i%n].x*(poly[(i+1)%n].y-poly[i-1].y);
		
		S /= 2;
		return S;
	}
	
	double overlap(vector <string> polygon1, vector <string> polygon2)
	{
		vector<point> poly1, poly2;
		
		for(int i=0;i<polygon1.size();++i){
			istringstream is(polygon1[i]);
			int x,y;
			is>>x>>y;
			poly1.push_back(point((double)x,(double)y));
		}
		
		for(int i=0;i<polygon2.size();++i){
			istringstream is(polygon2[i]);
			int x,y;
			is>>x>>y;
			poly2.push_back(point((double)x,(double)y));
		}
		
		int N1 = poly1.size(),N2 = poly2.size();
		vector<point> Intersections;
		
		for(int i=0;i<N1;++i) for(int j=0;j<N2;++j){
			point I;
			
			if(lineIntersection(line(poly1[i],poly1[(i+1)%N1]),line(poly2[j],poly2[(j+1)%N2]),I))
				Intersections.push_back(I);
		}
		
		vector<point> poly;
		
		for(int i=0;i<N1;++i) if(PointInsideConvexPolygon(poly1[i],poly2)) poly.push_back(poly1[i]);
		for(int i=0;i<N2;++i) if(PointInsideConvexPolygon(poly2[i],poly1)) poly.push_back(poly2[i]);
		for(int i=Intersections.size()-1;i>=0;--i)
			if(PointInsideConvexPolygon(Intersections[i],poly2) && PointInsideConvexPolygon(Intersections[i],poly1))
				poly.push_back(Intersections[i]);
		
		if(poly.size()<3) return 0.0;
		
		vector<point> Hull = ConvexHull(poly);
		return fabs(signed_area(Hull));
	}
};
