#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class MazeWanderingEasy{
	public:
	
	struct node{
		int r,c,dec;
		
		node(){}
		
		node(int _r, int _c, int _dec){
			r = _r; c = _c; dec = _dec;
		}
	};
	
	int decisions(vector <string> maze){
		queue<node> Q;
		
		int R = maze.size(), C = maze[0].size(),r0,c0;
		bool visited[R][C];
		memset(visited,false,sizeof(visited));
		
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j)
				if(maze[i][j]=='M')
					Q.push(node(i,j,0)), visited[i][j] = true, r0 = i, c0 = j;
		
		int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
		
		while(!Q.empty()){
			node aux = Q.front();
			Q.pop();
			
			if(maze[aux.r][aux.c]=='*') return aux.dec;
			
			int cont = 0;
			
			for(int i=0;i<4;++i){
				int r2 = aux.r+dr[i], c2 = aux.c+dc[i];
				
				if(r2>=0 && r2<R && c2>=0 && c2<C && maze[r2][c2]!='X') ++cont;
			}
			
			int dec = 0;
			if(cont>2 || (cont>1 && aux.r==r0 && aux.c==c0)) dec = 1;
			
			for(int i=0;i<4;++i){
				int r2 = aux.r+dr[i], c2 = aux.c+dc[i];
				
				if(r2>=0 && r2<R && c2>=0 && c2<C && maze[r2][c2]!='X' && !visited[r2][c2]){
					visited[r2][c2] = true;
					Q.push(node(r2,c2,aux.dec+dec));
				}
			}
		}
		
		return -1;
	}
};
