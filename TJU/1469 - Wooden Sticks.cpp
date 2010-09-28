#include <cstdio>
#include <algorithm>

using namespace std;

struct stick{
    int l,w;
    
    stick(){}
    
    stick(int _l, int _w){
        l = _l; w = _w;
    }
    
    bool operator < (stick X) const{
        if(l!=X.l) return l<X.l;
        return w<X.w;
    }
}S[5000];

int main(){
    int T,n,m,lo,hi,mi,w[5000];
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i) scanf("%d %d",&S[i].l,&S[i].w);
        sort(S,S+n);
        
        w[0] = S[0].w;
        m = 1;
        
        for(int i=1;i<n;++i){
            lo = 0; hi = m;
            
            while(lo!=hi){
                mi = (lo+hi)/2;
                
                if(w[mi]>S[i].w) lo = mi+1;
                else hi = mi;
            }
            
            if(lo==m) ++m;
            w[lo] = S[i].w;
        }
        
        printf("%d\n",m);
    }
    
    return 0;
}
