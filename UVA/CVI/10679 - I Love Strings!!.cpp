#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_LEN 100000
#define ALPH_SIZE 123

char S[MAX_LEN+1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
    N = strlen(S);
    
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i<N;++i) ++cont[S[i]];
    for(int i = 1;i<ALPH_SIZE;++i) cont[i] += cont[i-1];
    for(int i = 0;i<N;++i) pos[--cont[S[i]]] = i;
    
    for(int i = 0;i<N;++i){
        bh[i] = (i==0 || S[pos[i]]!=S[pos[i-1]]);
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

int M;
char T[1001];

bool isLess(int idx){
    for(int i = 0;i<M && idx+i<N;++i){
        if(T[i]<S[idx+i]) return true;
        if(T[i]>S[idx+i]) return false;
    }
    
    return false;
}

int main(){
    int TC,Q;
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%s",S);
        build_suffix_array();
        
        scanf("%d",&Q);
        
        for(int q = 1;q<=Q;++q){
            scanf("%s",T);
            M = strlen(T);
            
            int lo = 0, hi = N-1, mi;
            bool less, greater;
            
            while(lo!=hi){
                mi = (lo+hi+1)>>1;
                if(isLess(pos[mi])) hi = mi-1;
                else lo = mi;
            }
            
            bool isSubstring = true;
            
            if(N-pos[lo]<M) isSubstring = false;
            else{
                for(int i = 0;i<M;++i)
                    if(S[pos[lo]+i]!=T[i])
                        isSubstring = false;
            }
            
            if(isSubstring) putc('y', stdout);
            else putc('n', stdout);
            putc('\n', stdout);
        }
    }
    
    return 0;
}
