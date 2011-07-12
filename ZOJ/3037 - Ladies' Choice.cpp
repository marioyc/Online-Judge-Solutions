#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int N,pref_men[MAX_N][MAX_N],pref_women[MAX_N][MAX_N];
int inv[MAX_N][MAX_N],cont[MAX_N],wife[MAX_N],husband[MAX_N];

void stable_marriage(){
	for(int i = 0;i<N;++i)
		for(int j = 0;j<N;++j)
			inv[i][pref_women[i][j]] = j;
	
	fill(cont,cont+N,0);
	fill(husband,husband+N,-1);
	
	int m,w,dumped;
	
	for(int i = 0;i<N;++i){
		m = i;
		
		while(m>=0){
			while(true){
				w = pref_men[m][cont[m]];
				++cont[m];
				
				if(husband[w]<0 || inv[w][m]<inv[w][husband[w]]) break;
			}
			
			dumped = husband[w];
			husband[w] = m;
			wife[m] = w;
			m = dumped;
		}
	}
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                scanf("%d",&pref_men[i][j]);
                --pref_men[i][j];
            }
        }
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                scanf("%d",&pref_women[i][j]);
                --pref_women[i][j];
            }
        }
        
        stable_marriage();
        
        for(int i = 0;i < N;++i)
            printf("%d\n",1 + wife[i]);
    }
    
    return 0;
}
