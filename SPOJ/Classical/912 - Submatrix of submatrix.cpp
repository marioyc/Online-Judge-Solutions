#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int P[1000][1000],P2[1001][1001];

int main(){
    int T,N,M,A,B,C,D;
    
    scanf("%d",&T);
    
    while(T--){
		scanf("%d %d %d %d %d %d",&N,&M,&A,&B,&C,&D);
		
		for(int i = 0;i < N;++i)
			scanf("%d",&P[i][0]);
		
		for(int i = 0;i < N;++i)
			for(int j = 1;j < M;++j)
				P[i][j] = (P[i][j - 1] * 71 + 17) % 100 + 1;
		
		for(int i = 0;i < N;++i)
			for(int j = 0;j < M;++j)
				P2[i + 1][j + 1] = P[i][j] + P2[i + 1][j] + P2[i][j + 1] - P2[i][j];
		
		deque< pair<int, int> > Q[M],Q2;
		int ans = 0;
		
		for(int i = 0;i < N;++i){
			for(int j = 0;j < M;++j)
				if(!Q[j].empty() && Q[j].front().second == i - A + C) Q[j].pop_front();
			
			Q2.clear();
			
			for(int j = 0;j < M;++j){
				if(!Q2.empty() && Q2.front().second == j - B + D) Q2.pop_front();
				
				if(i + 1 >= A && j + 1 >= B){
					int sum = P2[i + 1][j + 1] - P2[i + 1 - A][j + 1] - P2[i + 1][j + 1 - B] + P2[i + 1 - A][j + 1 - B];
					ans = max(ans,sum - Q2.front().first);
				}
				
				if(j >= C){
					while(!Q2.empty() && Q2.back().first > Q[j].front().first) Q2.pop_back();
					Q2.push_back(make_pair(Q[j].front().first,j));
				}
			}
			
			for(int j = 0;j < M;++j){
				if(i + 1 >= C && j + 1 >= D){
					int sum = P2[i + 1][j + 1] - P2[i + 1 - C][j + 1] - P2[i + 1][j + 1 - D] + P2[i + 1 - C][j + 1 - D];
					
					while(!Q[j].empty() && Q[j].back().first > sum) Q[j].pop_back();
					Q[j].push_back(make_pair(sum,i));
				}
			}
		}
		
		printf("%d\n",ans);
    }
    
    return 0;
}
