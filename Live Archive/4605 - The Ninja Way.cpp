#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_N 1000

int main(){
	int N,D;
	pair<int, int> P[MAX_N];
	vector<int> rest[MAX_N]; // restricciones a las que afecta cada variable
	int val_var[MAX_N], val_rest[MAX_N-1]; // valor actual de cada variable y restricción 
	
	while(true){
		scanf("%d %d",&N,&D);
		if(N==0 || D==0) break;
		
		for(int i = 0;i<N;++i){
			scanf("%d",&P[i].first);
			P[i].second = i;
		}
		
		sort(P,P+N);
		
		bool valid = true;
		
		for(int i = 0;i<N;++i) rest[i].clear();
		
		for(int i = 0;i+1<N;++i){
			int a = P[i].second, b = P[i+1].second;
			if(b<a) swap(a,b);
			
			if(b-a>D) valid = false;
			val_rest[i] = b-a;
			
			for(int j = a;j<b;++j) rest[j].push_back(i);
		}
		
		for(int i = 0;i+1<N;++i) val_var[i] = 1;
		
		int s = P[0].second, e = P[N-1].second, ans = -1;
		if(e<s) swap(s,e);
		
		if(valid){
			ans = 0;
			for(int i = s;i<e;++i){
				int inc = D;
				
				for(int j = rest[i].size()-1;j>=0;--j)
					inc = min(inc,D-val_rest[rest[i][j]]);
				
				if(inc>0){
					val_var[i] += inc;
					for(int j = rest[i].size()-1;j>=0;--j)
						val_rest[rest[i][j]] += inc;
				}
				
				ans += val_var[i];
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
