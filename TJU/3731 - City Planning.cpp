#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
		scanf("%d",&n);
		
		int x1[n],y1[n],x2[n],y2[n],val[n];
		int N = 2 * n;
		int x[N],y[N];
		
		for(int i = 0,j = 0;i < n;++i){
			scanf("%d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&val[i]);
			
			x[2*i] = x1[i]; x[2*i + 1] = x2[i];
			y[2*i] = y1[i]; y[2*i + 1] = y2[i];
		}
		
		sort(x,x + N);
		sort(y,y + N);
		
		long long ans = 0;
		
		for(int i = 0;i + 1 < N;++i){
			for(int j = 0;j + 1 < N;++j){
				int best = 0;
				
				for(int k = 0;k < n;++k)
					if(x[i] >= x1[k] && x[i + 1] <= x2[k] && y[j] >= y1[k] && y[j + 1] <= y2[k])
						best = max(best,val[k]);
				
				ans += (long long)(x[i + 1] - x[i]) * (y[j + 1] - y[j]) * best;
			}
		}
		
		printf("Case %d: %lld\n",tc,ans);
    }
    
    return 0;
}
