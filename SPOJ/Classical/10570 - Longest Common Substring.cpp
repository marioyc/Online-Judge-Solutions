#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_K = 10;
const int MAX_LEN = MAX_K * (10000 + 1);
const int ALPH_SIZE = 256;
const int LOG2_LEN = 16;

char A[MAX_LEN + 1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN + 1],b2h[MAX_LEN + 1];

void build_suffix_array(){
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i < N;++i) ++cont[A[i]];
    for(int i = 1;i < ALPH_SIZE;++i) cont[i] += cont[i-1];
    for(int i = 0;i < N;++i) pos[--cont[A[i]]] = i;
    
    for(int i = 0;i<N;++i){
        bh[i] = (i == 0 || A[pos[i]] != A[pos[i-1]]);
        b2h[i] = false;
    }
    
    for(int H = 1;H < N;H <<= 1){
        int buckets = 0;
        
        for(int i = 0,j;i < N;i = j){
            j = i+1;
            
            while(j < N && !bh[j]) ++j;
            next[i] = j;
            ++buckets;
        }
        
        if(buckets == N) break;
        
        for(int i = 0;i < N;i = next[i]){
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

void get_height(){
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

int RMQ[MAX_LEN][LOG2_LEN + 1];

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
int lcp(int x, int y){
    if(x == y) return N-rank[x];
    if(x > y) swap(x,y);
    
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    
    return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

int T,K,L[MAX_K];
char s[MAX_K][10001],c;
int id[MAX_LEN + 1];
int last[MAX_K];

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&K);
        
        for(int i = 0;i < K;++i){
			scanf("%s",s[i]);
			L[i] = strlen(s[i]);
		}
		
		N = 0;
		
		for(int i = 0;i < K;++i){
			for(int j = 0;;++j){
                if(s[i][j] >= 'a' && s[i][j] <= 'z'){
				    A[N] = s[i][j];
                    id[N++] = i;
                }else break;
            }
            
			A[N] = '0' + i;
			id[N++] = -1;
		}
		
		
		build_suffix_array();
		get_height();
		initialize_rmq();
        
        int ans = 0;
        memset(last,-1,sizeof last);
        
        for(int i = 0;i < N;++i){
            if(id[ pos[i] ] != -1){
                last[ id[ pos[i] ] ] = i;
                
                int st = i;
                
                for(int j = 0;j < K;++j)
                    st = min(st,last[j]);
                
                if(st != -1) ans = max(ans,lcp(st,i));
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
