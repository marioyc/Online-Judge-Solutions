#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100005

int s[MAXN];
vector< pair<int, int> > open,close;

int T[4 * MAXN],lazy[4 * MAXN];

void push(int node, int l, int r){
    if(lazy[node]){
        T[node] = r - l + 1 - T[node];
        
        if(l != r){
            lazy[2 * node + 1] ^= 1;
            lazy[2 * node + 2] ^= 1;
        }
        
        lazy[node] = 0;
    }
}

void pull(int node){
    T[node] = T[2 * node + 1] + T[2 * node + 2];
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return 0;
    
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    int ret1 = query(2 * node + 1,l,mi,x,y);
    int ret2 = query(2 * node + 2,mi + 1,r,x,y);
    pull(node);
    
    return ret1 + ret2;
}

void update(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return;
    
    if(x <= l && r <= y){
        lazy[node] = 1;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        update(2 * node + 1,l,mi,x,y);
        update(2 * node + 2,mi + 1,r,x,y);
        pull(node);
    }
}

int main(){
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&s[i]);
    sort(s,s + n);
    
    int m = 0;
    
    for(int i = 0,l,r;i < k;++i){
        scanf("%d %d",&l,&r);
        
        if(s[0] >= r || s[n - 1] <= l) continue;
        
        int lo = 0,hi = n - 1,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if(s[mi] < l) lo = mi + 1;
            else hi = mi;
        }
        
        l = lo;
        lo = 0; hi = n - 1;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(s[mi] > r) hi = mi - 1;
            else lo = mi;
        }
        
        r = lo;
        
        open.push_back(make_pair(l,r));
        close.push_back(make_pair(r,l));
        ++m;
    }
    
    sort(open.begin(),open.end());
    sort(close.begin(),close.end());
    
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    
    for(int i = 0,p1 = 0,p2 = 0;i < n;++i){
        while(p1 < m && open[p1].first == i){
            update(0,0,n - 1,open[p1].first,open[p1].second);
            ++p1;
        }
        
        int aux = i - query(0,0,n - 1,0,i - 1) + query(0,0,n - 1,i + 1,n - 1);
        ans -= (long long)aux * (aux - 1) / 2;
        
        while(p2 < m && close[p2].first == i){
            update(0,0,n - 1,close[p2].second,close[p2].first);
            ++p2;
        }
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
