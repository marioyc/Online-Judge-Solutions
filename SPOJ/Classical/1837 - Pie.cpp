#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int T,N,F;
    
    scanf("%d",&T);
    
    while(T--){
		scanf("%d %d",&N,&F);
		
		int r[N];
		
		for(int i = 0;i < N;++i){
			scanf("%d",&r[i]);
            r[i] *= r[i];
        }
		
		sort(r,r + N);
		
		double lo = 0,hi = 4e8,mi;
		
		for(int it = 0;it < 43;++it){
			mi = (lo + hi) / 2;
			
			int cont = 0;
			
			for(int i = N - 1;i >= 0 && cont <= F;--i)
				cont += (int)floor(M_PI * r[i] / mi);
			
			if(cont > F) lo = mi;
			else hi = mi;
		}
		
		printf("%.4f\n",lo);
    }
    
    return 0;
}
