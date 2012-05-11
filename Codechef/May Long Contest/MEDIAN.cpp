#include <cstdio>
#include <algorithm>

using namespace std;

int n,mi,cont;
bool found;

void solve(int mask, int lvl = 0){
    if(found) return;
    ++cont;
    
    if(mask == 0){
        found = true;
        return;
    }
    
    if(lvl < mi){
        for(int i = 0;i < n;++i){
            int cont = 0,mask2 = 0;
            
            for(int j = i;j < n;++j){
                cont += (mask & (1 << j))? 1 : 0;
                mask2 |= (1 << j);
                
                if(cont <= (j - i + 1) / 2 && cont > 0)
				    solve(mask & ~mask2,lvl + 1);
                
                if(found) return;
            }
        }
    }
}

int main(){
    int T,a[30];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        int mx = a[0];
        
        for(int i = 0;i < n;++i)
            mx = max(mx,a[i]);
        
        int mask = 0;
        
        for(int i = 0;i < n;++i)
            if(a[i] != mx)
                mask |= (1 << i);
        
        int lo = 0,hi = min(n - 1,5);
        cont = 0;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            found = false;
            solve(mask);
            
            if(!found) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
