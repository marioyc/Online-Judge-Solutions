#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 10000

struct event{
	int ind;
	bool type;
	
	event(){};
	event(int ind, int type) : ind(ind), type(type) {};
};

struct point{
	int x,y;
};

int N;
point rects[MAX_N][2];
event events_v[2*MAX_N],events_h[2*MAX_N];
bool in_set[MAX_N];

bool compare_x(event a, event b){ return rects[a.ind][a.type].x<rects[b.ind][b.type].x; }
bool compare_y(event a, event b){ return rects[a.ind][a.type].y<rects[b.ind][b.type].y; }

long long union_area(){
	int e = 0;	
	
	for(int i = 0;i<N;++i){
		events_v[e] = event(i,0);
		events_h[e] = event(i,0);
		++e;
		events_v[e] = event(i,1);
		events_h[e] = event(i,1);
		++e;
	}
	
	sort(events_v,events_v+e,compare_x);
	sort(events_h,events_h+e,compare_y);
	
	memset(in_set,false,sizeof(in_set));
	in_set[events_v[0].ind] = true;
	long long area = 0;
	
	int prev_ind = events_v[0].ind, cur_ind;
	int prev_type = events_v[0].type, cur_type;
	
	for(int i = 1;i<e;++i){
		cur_ind = events_v[i].ind; cur_type = events_v[i].type;
		int cont = 0, dx = rects[cur_ind][cur_type].x-rects[prev_ind][prev_type].x;
		int begin_y;
		
		if(dx!=0){
			for(int j = 0;j<e;++j){
				if(in_set[events_h[j].ind]){
					if(events_h[j].type==0){
						if(cont==0) begin_y = rects[events_h[j].ind][0].y;
						++cont;
					}else{
						--cont;
						if(cont==0){
							int dy = rects[events_h[j].ind][1].y-begin_y;
							area += (long long)dx*dy;
						}
					}
				}
			}
		}
		
		in_set[cur_ind] = (cur_type==0);
		prev_ind = cur_ind; prev_type = cur_type;
	}
	
	return area;
}

int main(){
	scanf("%d",&N);
	
	for(int i = 0;i<N;++i){
		scanf("%d %d %d %d",&rects[i][0].x,&rects[i][0].y,
							&rects[i][1].x,&rects[i][1].y);
	}
	
	printf("%lld\n",union_area());
	
	return 0;
}

