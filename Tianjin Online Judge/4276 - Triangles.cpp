#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 100

struct point{
	int x,y;
	
	point(){}
	
	bool operator < (point P)const{
		return x<P.x;
	}
}r[MAX_N],g[MAX_N],b[MAX_N];

int area(point &p1, point &p2, point &p3){
	return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y)-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
}

int main(){
	int R,G,B,tc = 1;
	int cont_r1[MAX_N][MAX_N],cont_r2[MAX_N];
	int cont_g1[MAX_N][MAX_N],cont_g2[MAX_N];
	
	while(true){
		scanf("%d %d %d",&R,&G,&B);
		if(R<0 || G<0 || B<0) break;
		
		for(int i = 0;i<R;++i) scanf("%d %d",&r[i].x,&r[i].y);
		for(int i = 0;i<G;++i) scanf("%d %d",&g[i].x,&g[i].y);
		for(int i = 0;i<B;++i) scanf("%d %d",&b[i].x,&b[i].y);
		
		memset(cont_r1,0,sizeof(cont_r1));
		memset(cont_r2,0,sizeof(cont_r2));
		memset(cont_g1,0,sizeof(cont_g1));
		memset(cont_g2,0,sizeof(cont_g2));
		sort(b,b+B);
		
		for(int i = 0;i<B;++i) for(int j = i+1;j<B;++j){
			for(int k = 0;k<R;++k)
				if(r[k].x>=b[i].x && r[k].x<=b[j].x && area(b[i],r[k],b[j])>0)
					++cont_r1[i][j], ++cont_r1[j][i];
			
			for(int k = 0;k<G;++k)
				if(g[k].x>=b[i].x && g[k].x<=b[j].x && area(b[i],g[k],b[j])>0)
					++cont_g1[i][j], ++cont_g1[j][i];
		}
		
		for(int i = 0;i<B;++i)
			for(int j = 0;j<R;++j)
				if(r[j].x==b[i].x && r[j].y<b[i].y)
					++cont_r2[i];
		
		for(int i = 0;i<B;++i)
			for(int j = 0;j<G;++j)
				if(g[j].x==b[i].x && g[j].y<b[i].y)
					++cont_g2[i];
		
		int ans1 = 0, ans2 = 0;
		
		for(int i = 0;i<B;++i){
			for(int j = i+1;j<B;++j){
				for(int k = j+1;k<B;++k){
					int total_r = 0, total_g = 0;
					
					if(area(b[i],b[j],b[k])>0){
						total_r = cont_r1[i][k]-cont_r1[i][j]-cont_r1[j][k]+cont_r2[j];
						total_g = cont_g1[i][k]-cont_g1[i][j]-cont_g1[j][k]+cont_g2[j];
					}else{
						total_r = cont_r1[i][j]+cont_r1[j][k]-cont_r1[i][k]-cont_r2[j];
						total_g = cont_g1[i][j]+cont_g1[j][k]-cont_g1[i][k]-cont_g2[j];
					}
					
					if(total_r>total_g) ++ans1;
					if(total_r<total_g) ++ans2;
				}
			}
		}
		
		printf("Case %d: %d %d\n",tc++,ans1,ans2);
	}
	
	return 0;
}
