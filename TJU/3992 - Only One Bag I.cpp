#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,n,m,a[7];
    bool M[7][7];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        memset(M,false,sizeof M);
        
        for(int i = 0,x,y;i < m;++i){
            scanf("%d %d",&x,&y);
            --x; --y;
            M[x][y] = true;
        }
        
        for(int i = 0;i < n;++i)
            a[i] = i;
        int ans = 0;
        
        do{
            bool ok = true;
            
            for(int i = 0;i < n;++i)
                for(int j = i + 1;j < n;++j)
                    if(M[ a[j] ][ a[i] ])
                        ok = false;
            
            if(ok) ++ans;
        }while(next_permutation(a,a + n));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
