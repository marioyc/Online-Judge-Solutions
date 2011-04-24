#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,m,x[1000],y[1000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        --n; --m;
        
        for(int i = 0;i < n;++i) scanf("%d",&x[i]);
        for(int i = 0;i < m;++i) scanf("%d",&y[i]);
        
        int ans,s1 = 0,s2 = 0;
        for(int i = 0;i < n;++i) s1 += x[i];
        for(int i = 0;i < m;++i) s2 += y[i];
        ans = s1+s2;
        
        sort(x,x+n);
        sort(y,y+m);
        
        for(int i = n-1,j = m-1;i >= 0 && j >= 0;){
            if(y[j] >= x[i]){
                ans += s1;
                s2 -= y[j];
                --j;
            }else{
                ans += s2;
                s1 -= x[i];
                --i;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
