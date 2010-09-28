#include <cstdio>
#include <cstring>

using namespace std;

int X,Y,Qx[10000],Qy[10000],head,tail,x,y,x1,y1,x2,y2;
bool visited[100][100];
bool no[100][100];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

bool valid(int &x, int &y){
	return (x>=0 && x<X && y>=0 && y<Y && !no[x][y]);
}

bool path(int &xs, int &ys, int &xe, int &ye){
	memset(visited,false,sizeof(visited));
	
	Qx[0]=xs; Qy[0]=ys;
	head=0; tail=1;
	visited[xs][ys]=true;
	
	while(head!=tail){
		x=Qx[head]; y=Qy[head];
		head++;
		
		if(x==xe && y==ye) return true;
		
		for(int i=0;i<4;i++){
			x1=x+dx[i]; y1=y+dy[i];
			x2=xe-(x1-xs); y2=ye-(y1-ys);
			
			if(valid(x1,y1) && valid(x2,y2) && !visited[x1][y1]){
				Qx[tail]=x1; Qy[tail]=y1;
				tail++;
				visited[x1][y1]=true;
			}
		}
	}
	
	return false;
}

int main(){
	int N,xs,ys,xe,ye,x,y;
	
	while(1){
		scanf("%d %d",&X,&Y);
		
		if(X==0) break;
		
		scanf("%d %d %d %d %d",&xs,&ys,&xe,&ye,&N);
		
		memset(no,false,sizeof(no));
		
		for(int i=0;i<N;i++){
			scanf("%d %d",&x,&y);
			no[x][y]=true;
		}
		
		if(path(xs,ys,xe,ye)) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
