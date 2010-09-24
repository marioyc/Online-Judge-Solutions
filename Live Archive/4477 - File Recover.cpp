#include <cstdio>
#include <cstring>

using namespace std;

#define max(x,y) (x)>(y)? (x):(y)

// Construcción en O(nlgn)

#define MAX_LEN 100000
#define ALPH_SIZE 123

char A[MAX_LEN+1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
	N = strlen(A);
	
	// bucket sort por la primera letra
	memset(cont,0,sizeof(cont));
	
	
	for(int i = 0;i<N;++i) ++cont[A[i]];
	for(int i = 1;i<ALPH_SIZE;++i) cont[i] += cont[i-1];
	for(int i = 0;i<N;++i) pos[--cont[A[i]]] = i;
	
	for(int i = 0;i<N;++i){
		bh[i] = (i==0 || A[pos[i]]!=A[pos[i-1]]);
		b2h[i] = false;
	}
	
	/*
		Hemos ordenado en base a los prefijos de longitud H queremos
		ordenar por los de longitud 2*H, al inicio del paso H, pos[i]
		contiene la posición inicial de	i-ésimo menor sufijo (deacuerdo
		a los primeros H caracteres), prm[i] es la inversa de pos, es
		decir prm[pos[i]] = i, y bh[i] = 1 si y sólo si pos[i] contiene
		el sufijo más a la izquierda de un H-bucket. cont y b2h son
		arreglos temporales.
	*/
	
	for(int H = 1;H<N;H <<= 1){
		int buckets = 0;
		
		for(int i = 0,j;i<N;i = j){
			j = i+1;
			
			while(j<N && !bh[j]) ++j;
			next[i] = j;
			++buckets;
		}
		
		if(buckets==N) break;
		
		for(int i = 0;i<N;i = next[i]){
			cont[i] = 0;
			for(int j = i;j<next[i];++j)
				rank[pos[j]] = i;
		}
		
		++cont[rank[N-H]];
		b2h[rank[N-H]] = true;
		
		for(int i = 0;i<N;i = next[i]){
			for(int j = i;j<next[i];++j){
				int s = pos[j]-H;
				
				if(s>=0){
					int head = rank[s];
					rank[s] = head+cont[head];
					++cont[head];
					b2h[rank[s]] = true;
				}
			}
			
			for(int j = i;j<next[i];++j){
				int s = pos[j]-H;
				
				if(s>=0 && b2h[rank[s]]){
					for(int k = rank[s]+1;!bh[k] && b2h[k];++k)
						b2h[k] = false;
				}
			}
		}
		
		for(int i = 0;i<N;++i){
			pos[rank[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	
	for(int i = 0;i<N;++i) rank[pos[i]] = i;
}

int height[MAX_LEN];
// height[i] = lcp(pos[i],pos[i-1])
// height[0] = 0

// Complejidad : O(n)
void getHeight(){
	height[0] = 0;
	
	for(int i = 0,h = 0;i<N;++i){
		if(rank[i]>0){
			int j = pos[rank[i]-1];
			
			while(i+h<N && j+h<N && A[i+h]==A[j+h]) ++h;
			height[rank[i]] = h;
			if(h>0) --h;
		}
	}
}

int main(){
	while(true){
		scanf("%s",A);
		if(A[0]=='*') break;
		
		build_suffix_array();
		getHeight();
		
		int ans = 0;
		for(int i = 1;i<N;++i) ans += max(0,height[i]-height[i-1]);
		printf("%d\n",ans);
	}
	
	return 0;
}
