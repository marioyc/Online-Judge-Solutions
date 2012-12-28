#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LEN 300000
#define ALPH_SIZE 123

char A[MAX_LEN+1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
    N = strlen(A);
    
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

#define le(x) (2*x+1)
#define ri(x) (2*x+2)

int T[4 * MAX_LEN],lazy[4 * MAX_LEN];

void push(int node, int l, int r){
    T[node] = max(T[node],lazy[node]);
    
    if(l != r){
        lazy[le(node)] = max(lazy[le(node)],lazy[node]);
        lazy[ri(node)] = max(lazy[ri(node)],lazy[node]);
    }
}

void pull(int node){
    T[node] = max(T[le(node)],T[ri(node)]);
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return 0;
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    int ret = max(query(le(node),l,mi,x,y),query(ri(node),mi + 1,r,x,y));
    pull(node);
    
    return ret;
}

void update(int node, int l, int r, int x, int y, int val){
    push(node,l,r);
    if(r < x || l > y) return;
    
    if(x <= l && r <= y){
        lazy[node] = val;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        
        update(le(node),l,mi,x,y,val);
        update(ri(node),mi + 1,r,x,y,val);
        pull(node);
    }
}

char s[MAX_LEN];
int lens;

pair<int,int> search(){
    int l = 0,r = N - 1;
    
    for(int i = 0;i < lens;++i){
        int lo = l,hi = r,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if(A[ pos[mi] + i ] < s[i]) lo = mi + 1;
            else hi = mi;
        }
        
        if(A[ pos[lo] + i ] != s[i]) return make_pair(-1,-1);
        l = lo;
        
        lo = l; hi = r;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(A[ pos[mi] + i ] > s[i]) hi = mi - 1;
            else lo = mi;
        }
        
        r = lo;
    }
    
    return make_pair(l,r);
}

int main(){
    scanf("%d %s",&N,A);
    build_suffix_array();
    
    int M;
    
    scanf("%d",&M);
    
    for(int i = 0;i < M;++i){
        scanf("%s",s);
        lens = strlen(s);
        
        pair<int,int> p = search();
        
        if(p.first != -1)
            update(0,0,N - 1,p.first,p.second,lens);
    }
    
    vector< pair<int, int> > v;
    
    for(int i = 0;i < N;++i){
        int l = pos[i];
        int r = l + query(0,0,N - 1,i,i) - 1;
        if(l <= r) v.push_back(make_pair(l,r));
    }
    
    sort(v.begin(),v.end());
    int nv = v.size();
    
    int ans = 0;
    
    for(int i = 0,pos = 0;i < N;){
        if(pos == nv || v[pos].first != i){
            ++ans;
            ++i;
        }else{
            int e = v[pos++].second;
            
            while(pos < nv && v[pos].first <= e + 1){
                e = max(e,v[pos].second);
                ++pos;
            }
            
            i = e + 1;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
