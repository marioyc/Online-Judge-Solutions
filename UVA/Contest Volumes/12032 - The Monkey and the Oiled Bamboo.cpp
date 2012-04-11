#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int tc = 1,T,n,r[100001];
    r[0] = 0;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 1;i <= n;++i)
            scanf("%d",&r[i]);
        
        sort(r,r + n);
        
        int lo = 0,hi = 10000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            bool ok = true;
            
            for(int i = 0,k = mi;i + 1 <= n && ok;++i){
                if(r[i + 1] - r[i] > k) ok = false;
                else if(r[i + 1] - r[i] == k) --k;
            }
            
            if(!ok) lo = mi + 1;
            else hi = mi;
        }
        
        printf("Case %d: %d\n",tc++,lo);
    }
    
    return 0;
}
