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
#include <climits>
#include <cstring>

using namespace std;

class CollectingRiders
{
public:
	struct node{
		int r,c,dist;
		
		node(){}
		node(int r, int c, int dist) : r(r), c(c), dist(dist){}
	}aux;
	
	int minimalMoves(vector <string> board)
	{
		int R = board.size(), C = board[0].size();
		
		int H = 0,cont[R][C],ans[R][C];
		memset(ans,0,sizeof(ans));
		memset(cont,0,sizeof(cont));
		
		bool visited[R][C];
		
		int dr[] = {-2,-2,2,2,-1,-1,1,1};
		int dc[] = {-1,1,-1,1,-2,2,-2,2};
		
		for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
			if(board[i][j]!='.'){
				int K = board[i][j]-'0';
				++H;
				
				memset(visited,false,sizeof(visited));
				
				queue<node> Q;
				visited[i][j] = true;
				Q.push(node(i,j,0));
				
				while(!Q.empty()){
					aux = Q.front();
					Q.pop();
					ans[aux.r][aux.c] += (aux.dist+K-1)/K;
					++cont[aux.r][aux.c];
					
					for(int dir = 0;dir<8;++dir){
						int r2 = aux.r+dr[dir];
						int c2 = aux.c+dc[dir];
						
						if(r2>=0 && r2<R && c2>=0 && c2<C && !visited[r2][c2]){
							visited[r2][c2] = true;
							Q.push(node(r2,c2,aux.dist+1));
						}
					}
				}
				
				
			}
		}
		
		int ret = INT_MAX;
		
		for(int i = 0;i<R;++i)
			for(int j = 0;j<C;++j)
				if(cont[i][j]==H)
					ret = min(ret,ans[i][j]);
		
		return (ret==INT_MAX? -1 : ret);
	}
};
