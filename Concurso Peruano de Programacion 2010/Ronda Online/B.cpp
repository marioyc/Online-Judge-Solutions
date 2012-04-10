#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool empty[102][102],visited[102][102];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int bfs(int rs, int cs){
	if(empty[rs][cs]) return 0;
	
	int ans = 0;
	memset(visited,false,sizeof(visited));
	
	queue< pair<int, int> > Q;
	Q.push(make_pair(rs,cs));
	visited[rs][cs] = true;
	
	while(!Q.empty()){
		pair<int, int> aux = Q.front();
		Q.pop();
		++ans;
		
		for(int i = 0;i<8;++i){
			int r2 = aux.first+dr[i];
			int c2 = aux.second+dc[i];
			
			if(!visited[r2][c2] && !empty[r2][c2]){
				Q.push(make_pair(r2,c2));
				visited[r2][c2] = true;
			}
		}
	}
	
	return ans;
}

int main(){
	int T,R,C,N,r,c;
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&R,&C);
		scanf("%d",&N);
		
		memset(empty,true,sizeof(empty));
		
		for(int i = 0;i<N;++i){
			scanf("%d %d",&r,&c);
			empty[r][c] = false;
		}
		
		scanf("%d %d",&r,&c);
		
		printf("Caso #%d: %d\n",tc,bfs(r,c));
	}
	
	return 0;
}
