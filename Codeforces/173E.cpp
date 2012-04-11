#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define MAXN 100000
#define MAXQ 100000

int n;

struct person{
    int r,a;
    
    person(){}
    
    bool operator < (person X)const{
        return r < X.r;
    }
}P[MAXN];

int m,A[MAXN];

int get_age_id(int x){
    int lo = 0,hi = m - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(A[mi] < x) lo = mi + 1;
        else hi = mi;
    }
    
    return lo;
}

int bit[MAXN + 1];

void update(int idx, int val){
    for(int x = idx; x <= MAXN; x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int gsize[MAXN];

struct event{
    int id,r,al,ar,flag;
    
    event(){}
    
    bool operator < (event X)const{
        return r < X.r;
    }
}E[MAXQ];

int ans[MAXQ];

int T[4 * MAXN];

void update(int node, int l, int r, int x, int val){
    T[node] = max(T[node],val);
    
    if(l == r) return;
    
    int mi = (l + r) >> 1;
    
    if(x <= mi) update(2 * node + 1,l,mi,x,val);
    else update(2 * node + 2,mi + 1,r,x,val);
}

int query(int node, int l, int r, int a, int b){
    if(r < a || l > b) return 0;
    if(l >= a && r <= b) return T[node];
    
    int mi = (l + r) >> 1;
    
    return max(query(2 * node + 1,l,mi,a,b),query(2 * node + 2,mi + 1,r,a,b));
}

int main(){
    int k;
    
    scanf("%d %d",&n,&k);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&P[i].r);
    
    for(int i = 0;i < n;++i){
        scanf("%d",&P[i].a);
        A[i] = P[i].a;
    }
    
    int Q;
    scanf("%d",&Q);
    
    for(int i = 0,x,y;i < Q;++i){
        scanf("%d %d",&x,&y);
        
        E[i].id = i;
        E[i].r = max(P[x - 1].r,P[y - 1].r);
        
        int ax = min(P[x - 1].a,P[y - 1].a),ay = max(P[x - 1].a,P[y - 1].a);
        int al = ay - k,ar = ax + k;
        
        if(al <= ar){
            E[i].al = al;
            E[i].ar = ar;
            E[i].flag = 0;
        }else E[i].flag = -1;
    }
    
    sort(P,P + n);
    sort(A,A + n);
    sort(E,E + Q);
    
    m = 1;
    
    for(int i = 1;i < n;++i){
        if(A[i] != A[m - 1])
            A[m++] = A[i];
    }
    
    for(int i = 0;i < n;){
        int e = i;
        
        while(e < n && P[e].r == P[i].r) ++e;
        
        for(int j = i;j < e;++j)
            update(1 + get_age_id(P[j].a),1);
        
        for(int j = i;j < e;++j){
            int al = P[j].a - k,ar = P[j].a + k;
            int lo = 0,hi = m - 1,mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(al > A[mi]) lo = mi + 1;
                else hi = mi;
            }
            
            al = lo;
            lo = 0;hi = m - 1;
            
            while(lo < hi){
                mi = (lo + hi + 1) >> 1;
                
                if(ar < A[mi]) hi = mi - 1;
                else lo = mi;
            }
            
            ar = lo;
            
            //[l,r]
            
            gsize[j] = query(ar + 1) - query(al);
        }
        
        i = e;
    }
    
    for(int i = n - 1,j = Q - 1;i >= 0;--i){
        update(0,0,m - 1,get_age_id(P[i].a),gsize[i]);
        
        while(j >= 0 && (E[j].flag == -1 || i == 0 || P[i - 1].r < E[j].r)){
            if(E[j].flag != -1){
                int al = E[j].al,ar = E[j].ar;
                int lo = 0,hi = m - 1,mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    if(al > A[mi]) lo = mi + 1;
                    else hi = mi;
                }
                
                al = lo;
                lo = 0; hi = m - 1;
                
                while(lo < hi){
                    mi = (lo + hi + 1) >> 1;
                    
                    if(ar < A[mi]) hi = mi - 1;
                    else lo = mi;
                }
                
                ar = lo;
                
                ans[ E[j].id ] = query(0,0,m - 1,al,ar);
            }
            
            --j;
        }
    }
    
    for(int i = 0;i < Q;++i)
        printf("%d\n",ans[i] == 0? -1 : ans[i]);
    
    return 0;
}
