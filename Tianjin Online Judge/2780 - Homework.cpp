#include <cstdio>
#include <algorithm>

using namespace std;

struct homework{
    int t,w;

    homework(){}

    homework(int _t, int _w){
        t = _t; w = _w;
    }

    bool operator < (homework X) const{
        return w*X.t>t*X.w;
    }
}L[1000];

int main(){
    int T,n,C,ans;
    scanf("%d",&T);

    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);

        for(int i=0;i<n;++i) scanf("%d",&L[i].t);
        for(int i=0;i<n;++i) scanf("%d",&L[i].w);

        sort(L,L+n);
        ans = C = 0;
        
        for(int i=0;i<n;++i){
            C += L[i].t;
            ans += L[i].w*C;
        }

        printf("%d\n",ans);
    }
    
    return 0;
}
