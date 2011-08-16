#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct obj{
	int id,t;
	
	obj(){}
	
	obj(int _id, int _t){
		id = _id; t = _t;
	}
	
	bool operator < (obj X)const{
		return t < X.t;
	}
}aux;

int main(){
	int C,N,B,used,id[100000],last[100000],nxt[100000],ans;
	bool in_cache[100000];
	
	while(scanf("%d %d %d",&C,&N,&B) == 3){
		for(int i = 0;i < B;++i)
			scanf("%d",&id[i]);
		
		for(int i = 0;i < N;++i)
			last[i] = B;
		
		for(int i = B-1;i >= 0;--i){
			nxt[i] = last[id[i]];
			last[id[i]] = i;
		}
		
		memset(in_cache,false,sizeof(in_cache));
		priority_queue<obj> Q;
		ans = used = 0;
		
		for(int i = 0,x;i < B;++i){
			x = id[i];
			
			if(!in_cache[x]){
				in_cache[x] = true;
				++ans;
			
				if(used < C) ++used;
				else{
					aux = Q.top();
					Q.pop();
					in_cache[aux.id] = false;
				}
			}
			
			Q.push(obj(x,nxt[i]));
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
