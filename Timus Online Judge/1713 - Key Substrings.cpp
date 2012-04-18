#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_LEN 101000
#define ALPH_SIZE 1026

int A[MAX_LEN+1];
int N,pos[MAX_LEN],sf_rank[MAX_LEN];
int cont[MAX_LEN],nxt[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
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
            nxt[i] = j;
            ++buckets;
        }
        
        if(buckets==N) break;
        
        for(int i = 0;i<N;i = nxt[i]){
            cont[i] = 0;
            for(int j = i;j<nxt[i];++j)
                sf_rank[pos[j]] = i;
        }
        
        ++cont[sf_rank[N-H]];
        b2h[sf_rank[N-H]] = true;
        
        for(int i = 0;i<N;i = nxt[i]){
            for(int j = i;j<nxt[i];++j){
                int s = pos[j]-H;
        
                if(s>=0){
                    int head = sf_rank[s];
                    sf_rank[s] = head+cont[head];
                    ++cont[head];
                    b2h[sf_rank[s]] = true;
                }
            }
            
            for(int j = i;j<nxt[i];++j){
                int s = pos[j]-H;
                
                if(s>=0 && b2h[sf_rank[s]]){
                    for(int k = sf_rank[s]+1;!bh[k] && b2h[k];++k)
                        b2h[k] = false;
                }
            }
        }
        
        for(int i = 0;i<N;++i){
            pos[sf_rank[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    
    for(int i = 0;i<N;++i) sf_rank[pos[i]] = i;
}

int height[MAX_LEN];

void get_height(){
    height[0] = 0;
    
    for(int i = 0,h = 0;i<N;++i){
        if(sf_rank[i]>0){
            int j = pos[sf_rank[i]-1];
            
            while(i+h<N && j+h<N && A[i+h]==A[j+h]) ++h;
            height[sf_rank[i]] = h;
            if(h>0) --h;
        }
    }
}

#define LOG2_LEN 16

int RMQ[MAX_LEN][LOG2_LEN + 1];

void init_rmq(){
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

int lcp(int x, int y){
    if(x==y) return N-sf_rank[x];
    if(x>y) swap(x,y);
    
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    
    return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

int str[MAX_LEN],len[MAX_LEN];
char s[101];

int main(){
    int n;
    
    scanf("%d",&n);
    
    N = 0;
    
    for(int i = 0,L;i < n;++i){
        scanf("%s",s);
        L = strlen(s);
        
        for(int j = 0;j < L;++j){
            A[N + j] = s[j] - 'a';
            str[N + j] = i;
            len[N + j] = L - j;
        }
        
        A[N + L] = 26 + i;
        str[N + L] = -1;
        
        N += L + 1;
    }
    
    build_suffix_array();
    get_height();
    init_rmq();
    
    N -= n;
    int ans[1000],ind[1000];
    
    for(int i = 0;i < n;++i)
        ans[i] = 101;
    
    for(int i = 0;i < N;){
        int e = i;
        
        while(e < N && str[ pos[e] ] == str[ pos[i] ]) ++e;
        
        for(int j = i;j < e;++j){
            int best = 0;
            
            if(i > 0) best = lcp(i - 1,j);
            if(e < N) best = max(best,lcp(j,e));
            
            if(1 + best <= len[ pos[j] ] && 1 + best < ans[ str[ pos[j] ] ]){
                ans[ str[ pos[j] ] ] = 1 + best;
                ind[ str[ pos[j] ] ] = pos[j];
            }
        }
        
        i = e;
    }
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < ans[i];++j)
            putchar('a' + A[ind[i] + j]);
        putchar('\n');
    }
    
    return 0;
}
