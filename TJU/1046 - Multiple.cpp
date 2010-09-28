#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool D[10],visited[5000];
int prev_mod[5000],prev_d[5000];
int Q[5000],head,tail;

void solve(int N){
	if(N==0){
		printf("0\n");
		return;
	}	
	
	memset(visited,false,sizeof(visited));
	
	head = tail = 0;
	
	for(int i = 1;i<10;++i){
		if(D[i] && !visited[i%N]){
			visited[i%N] = true;
			Q[tail] = i%N;
			++tail;
			
			prev_d[i%N] = i;
			prev_mod[i%N] = -1;
		}
	}
	
	while(head<tail){
		int aux = Q[head];
		++head;
		
		for(int i = 0;i<10;++i){
			int aux2 = (aux*10+i)%N;
			
			if(D[i] && !visited[aux2]){
				visited[aux2] = true;
				Q[tail] = aux2;
				++tail;
				
				prev_d[aux2] = i;
				prev_mod[aux2] = aux;
			}
		}
	}
	
	if(!visited[0]) printf("0\n");
	else{
		string ans;
		int cur = 0;
	
		while(cur!=-1){
			ans += (char)('0'+prev_d[cur]);
			cur = prev_mod[cur];
		}
		
		reverse(ans.begin(),ans.end());
		
		printf("%s\n",ans.c_str());
	}
}

int main(){
	int N,M,d;
	
	while(scanf("%d",&N)==1){
		scanf("%d",&M);
		
		for(int i = 0;i<10;++i)
			D[i] = false;
		
		for(int i = 0;i<M;++i){
			scanf("%d",&d);
			D[d] = true;
		}
		
		solve(N);
	}
	
	return 0;
}
