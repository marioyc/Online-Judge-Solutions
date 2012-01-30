#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,a[20000],b[20000];
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i) scanf("%d",&a[i]);
        for(int i = 0;i < m;++i) scanf("%d",&b[i]);
        
        int ans = 0;
        bool ok = true;
        
        sort(a,a + n);
        sort(b,b + m);
        
        for(int i = 0,j = 0;i < n && ok;++i){
            while(j < m && b[j] < a[i]) ++j;
            
            if(j == m) ok = false;
            else ans += b[j++];
        }
        
        if(!ok) puts("Loowater is doomed!");
        else printf("%d\n",ans);
    }
    
    return 0;
}
