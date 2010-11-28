#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_X 32001 

int T[MAX_X+1];

void update(int idx, int val){
	for(;idx<=MAX_X;idx += idx & -idx) T[idx] += val;
}

int F(int idx){
	int sum = 0;
	for(;idx>0;idx -= idx & -idx) sum += T[idx];
	return sum;
}

int main(){
	int N,x,y;
	scanf("%d",&N);
	
	int ans[N];
	memset(ans,0,sizeof(ans));
	memset(T,0,sizeof(T));
	
	for(int i = 0;i<N;++i){
		scanf("%d %d",&x,&y);
		++ans[F(x+1)];
		update(x+1,1);
	}
	
	for(int i = 0;i<N;++i)
		printf("%d\n",ans[i]);
	
	return 0;
}
