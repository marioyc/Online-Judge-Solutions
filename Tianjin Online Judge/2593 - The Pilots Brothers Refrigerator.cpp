#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node{
	int mask,dist;
	
	node(){}
	
	node(int _mask, int _dist){
		mask = _mask; dist = _dist;
	}
}aux;

int parent[(1<<16)],r[(1<<16)],c[(1<<16)];

int solve(int s){
	memset(parent,-1,sizeof(parent));
	
	queue<node> Q;
	Q.push(node(s,0));
	parent[0] = -2;
	
	while(!Q.empty()){
		aux = Q.front();
		Q.pop();
		
		if(aux.mask==(1<<16)-1) return aux.dist;
		
		for(int i = 0;i<4;++i) for(int j = 0;j<4;++j){
			int mask2 = aux.mask;
			
			for(int k = 0;k<4;++k) mask2 ^= (1<<(4*i+k));
			for(int k = 0;k<4;++k) mask2 ^= (1<<(4*k+j));
			mask2 ^= (1<<(4*i+j));
			
			if(parent[mask2]==-1){
				parent[mask2] = aux.mask;
				r[mask2] = i; c[mask2] = j;
				Q.push(node(mask2,aux.dist+1));
			}
		}
	}
}

int main(){
	char M[4][5];
	for(int i = 0;i<4;++i) scanf("%s",M[i]);
	
	int s = 0;
	
	for(int i = 0;i<4;++i)
		for(int j = 0;j<4;++j)
			if(M[i][j]=='-')
				s |= (1<<(4*i+j));
	
	int choice_r[(1<<16)],choice_c[(1<<16)],sz = solve(s);
	
	for(int i = 0,mask = (1<<16)-1;i<sz;++i){
		choice_r[i] = r[mask];
		choice_c[i] = c[mask];
		mask = parent[mask];
	}
	
	printf("%d\n",sz);
	for(int i = sz-1;i>=0;--i) printf("%d %d\n",1+choice_r[i],1+choice_c[i]);
	
	return 0;
}
