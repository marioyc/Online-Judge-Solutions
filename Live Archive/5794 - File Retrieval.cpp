#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LEN 600060
#define ALPH_SIZE 123

char A[MAX_LEN+1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
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

#define LOG2_LEN 19

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

// lcp(pos[x],pos[y])
int lcp(int x, int y){
    if(x==y) return N-rank[x];
    if(x>y) swap(x,y);
    
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    
    return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

int F;
long long mask[MAX_LEN];
long long RMQ2[MAX_LEN][LOG2_LEN + 1];

void mask_rmq(){
    for(int i = 0;i < N;++i) RMQ2[i][0] = mask[ pos[i] ];
    
    for(int j = 1;(1<<j) <= N;++j)
        for(int i = 0;i + (1<<j) - 1 < N;++i)
            RMQ2[i][j] = RMQ2[i][j-1] | RMQ2[i + (1 << (j-1))][j-1];
}

long long get_mask(int x, int y){
    int log = 0;
    while((1 << log) <= (y-x)) ++log;
    --log;
    
    return RMQ2[x][log] | RMQ2[y - (1<<log) + 1][log];
}

int main(){
    int len[60];
    
    while(true){
        scanf("%d",&F);
        if(F == 0) break;
        
        N = 0;
        
        vector<int> s;
        
        for(int i = 0;i < F;++i){
            scanf("%s",A + N);
            
            int L = strlen(A + N);
            len[i] = L;
            
            A[N + L] = i + 1;
            
            for(int j = 0;j < L;++j)
                mask[N + j] = (1LL << i);
            
            mask[N + L] = 0;
            
            s.push_back(N);
            N += L + 1;
        }
        
        A[N] = 0;
        
        if(F == 1){
            printf("1\n");
            continue;
        }
        
        build_suffix_array();
        get_height();
        init_rmq();
        mask_rmq();
        
        vector<long long> v;
        
        for(int i = F;i + 1 < N;++i){
            int cur = lcp(i,i + 1);
            
            if(cur > 0){
                int lo1 = F,hi1 = i,mi1;
                
                while(lo1 < hi1){
                    mi1 = (lo1 + hi1) >> 1;
                    
                    if(lcp(mi1,i + 1) < cur) lo1 = mi1 + 1;
                    else hi1 = mi1;
                }
                
                int lo2 = i,hi2 = N - 2,mi2;
                
                while(lo2 < hi2){
                    mi2 = (lo2 + hi2 + 1) >> 1;
                    
                    if(lcp(i,mi2 + 1) < cur) hi2 = mi2 - 1;
                    else lo2 = mi2;
                }
                
                long long ret = get_mask(lo1,lo2 + 1);
                
                if(__builtin_popcountll(ret) > 1) v.push_back(ret);
            }
        }
        
        sort(v.begin(),v.end());
        int ans = unique(v.begin(),v.end()) - v.begin();
        
        for(int i = 0;i < F;++i){
            int ind = rank[ s[i] ];
            bool ok = true;
            
            if(ind > 0 && lcp(ind - 1,ind) == len[i]) ok = false;
            if(ind + 1 < N && lcp(ind,ind + 1) == len[i]) ok = false;
            
            if(ok) ++ans;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
