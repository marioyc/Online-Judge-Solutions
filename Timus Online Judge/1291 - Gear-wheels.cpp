#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	while(a % b != 0){
		a %= b;
		swap(a,b);
	}
	
	return b;
}

int main(){
	int N,K[1000];
	vector<int> adj[1000];
	
	scanf("%d",&N);
	
	for(int i = 0,v;i < N;++i){
		scanf("%d",&K[i]);
		
		while(true){
			scanf("%d",&v);
			if(v == 0) break;
			adj[i].push_back(v-1);
		}
	}
	
	int s,V,num[1000],den[1000];
	bool visited[1000];
	
	scanf("%d %d",&s,&V);
	--s;
	
	for(int i = 0;i < N;++i){
		num[i] = 0;
		den[i] = 1;
		visited[i] = false;
	}
	
	num[s] = V;
	den[s] = 1;
	visited[s] = true;
	
	int Q[1000],head = 0,tail = 0;
	Q[tail++] = s;
	
	while(head < tail){
		int cur = Q[head++];
		
		for(int i = adj[cur].size()-1;i >= 0;--i){
			int nxt = adj[cur][i];
			
			if(!visited[nxt]){
				num[nxt] = -num[cur] * K[cur];
				den[nxt] = den[cur] * K[nxt];
				
				int g = gcd(abs(num[nxt]),den[nxt]);
				
				num[nxt] /= g;
				den[nxt] /= g;
				
				Q[tail++] = nxt;
				visited[nxt] = true;
			}
		}
	}
	
	for(int i = 0;i < N;++i)
		printf("%d/%d\n",num[i],den[i]);
	
	return 0;
}
