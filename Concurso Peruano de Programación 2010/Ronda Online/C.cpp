#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define MAX_LEN 100000
#define ALPH_SIZE 123

string A;
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
    N = A.size();
	
    memset(cont,0,sizeof(cont));
	
    for(int i = 0;i<N;++i) ++cont[A[i]];
    for(int i = 1;i<ALPH_SIZE;++i) cont[i] += cont[i-1];
    for(int i = 0;i<N;++i) pos[--cont[A[i]]] = i;
	
    for(int i = 0;i<N;++i){
        bh[i] = (i==0 || A[pos[i]]!=A[pos[i-1]]);
        b2h[i] = false;
    }
	
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

int main(){
	int T,L1,L2;
	pair<int,int> poss[MAX_LEN];
	char s1[MAX_LEN+1],s2[201];
	bool in[26];
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%s",s1);
		L1 = strlen(s1);
		
		scanf("%s",s2);
		L2 = strlen(s2);
		
		memset(in,false,sizeof(in));
		
		for(int i = 0;i<L2;++i)
			in[s2[i]-'A'] = true;
		
		int cont3[L1+1][26];
		memset(cont3,0,sizeof(cont3));
		
		for(int i = 1;i<=L1;++i){
			for(int j = 0;j<26;++j)
				cont3[i][j] = cont3[i-1][j];
			
			++cont3[i][s1[i-1]-'A'];
		}
		
		int cont2[26];
		memset(cont2,0,sizeof(cont2));
		
		for(int i = 0;i<L2;++i) ++cont2[s2[i]-'A'];
		
		int shortest = -1,sz = 0;
		
		for(int i = 0;i<L1;++i){
			if(!in[s1[i]-'A']) continue;
			
			bool valid = true;
			
			for(int j = 0;j<26;++j)
				if(in[j] && cont3[L1][j]-cont3[i][j]<cont2[j])
					valid = false;
			
			if(valid){
				int lo = i, hi = L1-1,mi;
				
				while(lo!=hi){
					mi = (lo+hi)/2;
					
					valid = true;
					
					for(int j = 0;j<26 && valid;++j){
						if(!in[j]) continue;
						valid = (cont3[mi+1][j]-cont3[i][j]<cont2[j]);
					}
					
					if(!valid) lo = mi+1;
					else hi = mi;
				}
				
				int aux = lo-i+1;
				
				if(shortest==-1 || aux<shortest)
					shortest = aux;
				
				poss[sz++] = make_pair(i,lo);
			}
		}
		
		A = string(s1);
		build_suffix_array();
		
		printf("Caso #%d: ",tc);
		
		if(sz==0) printf("NO ES DOMINANTE\n");
		else{
			int ans_s = -1, ans_e = -1;
			
			for(int i = 0;i<sz;++i){
				int s = poss[i].first, e = poss[i].second;
			
				if(e-s+1==shortest){
					if(ans_s==-1 || rank[s]<rank[ans_s]){
						ans_s = s;
						ans_e = e;
					}
				}
			}
			
			for(int i = ans_s;i<=ans_e;++i)
				printf("%c",s1[i]);
			printf("\n");
		}
	}
	
	return 0;
}
