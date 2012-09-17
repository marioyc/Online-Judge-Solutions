#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int t[1000000],last[1000001];
int ans[1000000];
set< pair<int, int> > S;
set< pair<int, int> > :: iterator it;

int main(){
    int T,n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < m;++i)
            scanf("%d",&t[i]);
        
        S.clear();
        int cont = 0;
        bool ok = true;
        memset(last,-1,sizeof last);
        
        for(int i = 0;i < m && ok;++i){
            if(t[i] == 0){
                ans[cont] = 0;
                S.insert(make_pair(i,cont++));
            }else{
                it = S.lower_bound(make_pair(last[ t[i] ],0));
                
                if(it == S.end()) ok = false;
                else{
                    ans[it->second] = t[i];
                    last[ t[i] ] = i;
                    S.erase(it);
                }
            }
        }
        
        if(!ok) puts("NO");
        else{
            puts("YES");
            
            for(int i = 0;i < cont;++i){
                if(i) putchar(' ');
                printf("%d",ans[i]);
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
