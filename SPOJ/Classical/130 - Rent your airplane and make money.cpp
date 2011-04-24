#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct order{
    int s,e,p;
    
    order(){}
    
    order(int _s, int _e, int _p){
        s = _s; e = _e; p = _p;
    }
    
    bool operator < (order X)const{
        return e < X.e;
    }
}O[10000];

int a[2 * 10000],sz;

int get_ind(int x){
    int lo = 0,hi = sz-1,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(a[mi] < x) lo = mi+1;
        else hi = mi;
    }
    
    return lo;
}

int T[4 * 2 * 10000];

int query(int node, int s, int e, int x){
    if(x < s) return 0;
    if(x >= e) return T[node];
    
    int mi = (s+e) >> 1;
    return max(query(2*node+1,s,mi,x),query(2*node+2,mi+1,e,x));
}

void update(int x, int val){
    int node = 0,s = 0,e = sz-1,mi;
    
    if(val > T[0]) T[0] = val;
    
    while(s < e){
        mi = (s+e) >> 1;
        
        if(x <= mi){
            node = 2*node+1;
            e = mi;
        }else{
            node = 2*node+2;
            s = mi+1;
        }
        
        if(val > T[node]) T[node] = val;
    }
}

int main(){
    int tc,n;
    
    scanf("%d",&tc);
    
    while(tc--){
        scanf("%d",&n);
        sz = 0;
        
        for(int i = 0,s,d,p;i < n;++i){
            scanf("%d %d %d",&s,&d,&p);
            O[i] = order(s,s+d-1,p);
            a[sz++] = s;
            a[sz++] = s+d-1;
        }
        
        sort(a,a+sz);
        int sz2 = 1;
        
        for(int i = 1;i < sz;++i){
            if(a[i] != a[sz2-1]){
                a[sz2] = a[i];
                ++sz2;
            }
        }
        
        sz = sz2;
        
        sort(O,O+n);
        memset(T,0,sizeof(T));
        
        int ans = 0;
        
        for(int i = 0;i < n;++i){
            int aux = query(0,0,sz-1,get_ind(O[i].s)-1) + O[i].p;
            if(aux > ans) ans = aux;
            
            update(get_ind(O[i].e),aux);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
