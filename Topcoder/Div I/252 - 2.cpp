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
#include <queue>
#include <cstring>

using namespace std;

class WatchtowerSpotlight
{
public:
	struct node{
		int x,y,t;
		
		node(){}
		
		node(int _x, int _y, int _t){
			x = _x; y = _y; t = _t;
		}
	};
	
	int minX,maxX,minY,maxY,cx,cy,S,D;
	
	bool isValid(node N){
		//cout<<"N : "<<N.x<<" "<<N.y<<" "<<N.t<<endl;
		if(N.x<minX || N.x>maxX || N.y<minY || N.y>maxY || (N.x==0 && N.y==0)) return false;
		//cout<<"a "<<N.x*N.x+N.y*N.y<<" "<<D*D<<endl;
		if(N.x*N.x+N.y*N.y>D*D) return true;
		//cout<<"b"<<endl;
		double alpha = (N.t%S)*360.0/S, betha = (N.t%S+1)*360.0/S;
		if(N.t%S==S-1 && N.x>=0 && N.y==0) return false;
		
		double ang = acos(N.x/sqrt(N.x*N.x+N.y*N.y))*180/M_PI;
		if(N.y<0) ang = 360-ang;
		
		if(alpha-1e-9<=ang && ang<=betha+1e-9) return false;
		return true;
	}
	
	int solve(int sx, int sy, int ex, int ey){
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};
		
		bool visited[50][50][99];
		memset(visited,false,sizeof(visited));
		
		queue<node> Q;
		
		if(isValid(node(sx,sy,0))){
			Q.push(node(sx,sy,0));
			visited[sx+cx][sy+cy][0] = true;
		}
		
		while(!Q.empty()){
			node aux = Q.front();
			Q.pop();
			
			if(aux.x==ex && aux.y==ey) return aux.t;
			
			for(int i=0;i<4;++i){
				node aux2 = node(aux.x+dx[i],aux.y+dy[i],aux.t+1);
				
				if(isValid(aux2) && !visited[aux2.x+cx][aux2.y+cy][aux2.t%S]){
					visited[aux2.x+cx][aux2.y+cy][aux2.t%S] = true;
					Q.push(aux2);
				}
			}
		}
		
		return -1;
	}
	
	int quickestEscape(string start, string end, string watchtower)
	{
		int sx,sy,ex,ey;
		
		istringstream is1(start);
		is1>>sx>>sy;
		
		istringstream is2(end);
		is2>>ex>>ey;
		
		istringstream is3(watchtower);
		is3>>cx>>cy>>S>>D;
		
		minX = 0; maxX = 49; minY = 0; maxY = 49;
		
		sx -= cx; sy -= cy; ex -= cx; ey -= cy;
		minX -= cx; maxX -= cx; minY -= cy; maxY -= cy;
		
		return solve(sx,sy,ex,ey);
	}
};
