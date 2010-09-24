#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	double x1,y1,r1,x2,y2,r2;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
	
	if(r1<r2){
		swap(x1,x2);
		swap(y1,y2);
		swap(r1,r2);
	}
	
	double ans = 0.0;
	
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1-r2)*(r1-r2)) ans = M_PI*r2*r2;
	else if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1+r2)*(r1+r2)){
		double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double p = (d+r1+r2)/2;
		double A = sqrt(p*(p-r1)*(p-r2)*(p-d));
		double ang1 = acos((d*d+r1*r1-r2*r2)/(2*d*r1)), ang2 = acos((d*d+r2*r2-r1*r1)/(2*d*r2));
		
		ans = ang1*r1*r1+ang2*r2*r2-2*A;
	}
	
	printf("%.3lf\n",ans);
	
	return 0;
}
