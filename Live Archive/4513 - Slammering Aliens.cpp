#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// Construcción en O(nlgn)

#define MAX_LEN 40000
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

#define LOG2_LEN 16

int RMQ[MAX_LEN][LOG2_LEN];

// Complejidad : O(nlgn)
void initialize_rmq(){
	for(int i = 0;i<N;++i) RMQ[i][0] = height[i];
	
	for(int j = 1;(1<<j)<=N;++j){
		for(int i = 0;i+(1<<j)-1<N;++i){
			if(RMQ[i][j-1]<=RMQ[i+(1<<(j-1))][j-1])
				RMQ[i][j] = RMQ[i][j-1];
			else
				RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
		}
	}
}

// lcp(pos[x],pos[y])
// Complejidad : O(1)
int lcp(int x, int y){
	if(x==y) return N-rank[x];
	if(x>y) swap(x,y);
	
	int log = 0;
	while((1<<log)<=(y-x)) ++log;
	--log;
	
	return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

int main(){
	int m,lo,hi,mi;
	
	while(true){
		scanf("%d",&m);
		if(m==0) break;
		
		scanf("%s",A);
		
		build_suffix_array();
		getHeight();
		initialize_rmq();
		
		int maxL = 0, start = -1;
		for(int i = 0;i+m-1<N;++i) maxL = max(maxL,lcp(i,i+m-1));
		
		for(int s = 0;s<N;){
			if(N-pos[s]<maxL) ++s;
			else{
				int e = s,aux = 0,h = N-pos[s];
			
				while(e<N && h>=maxL){
					aux = max(aux,pos[e]);
					++e;
					if(e<N) h = min(h,height[e]);
				}
				
				if(e-s>=m) start = max(start,aux);
				s = e;
			}
		}
		
		if(maxL==0) printf("none\n");
		else printf("%d %d\n",maxL,start);
	}
	
	return 0;
}
