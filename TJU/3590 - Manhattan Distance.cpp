#include <cstdio>
#include <string>
#include <map>
#include <set>

using namespace std;

#define MAXQ 100000

multiset<int> S00,S01;
multiset<int>::iterator it;
map<string, int> id;
int n,x[MAXQ],y[MAXQ];

int main(){
    int T,Q,op,sz;
    char name[10];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&Q);
        
        S00.clear();
        S01.clear();
        id.clear();
        n = sz = 0;
        
        while(Q--){
            scanf("%d %s",&op,name);
            
            if(op == 1){
                scanf("%d %d",&x[n],&y[n]);
                
                S00.insert(x[n] + y[n]);
                S01.insert(x[n] - y[n]);
                id[name] = n;
                ++n; ++sz;
            }else{
                int cur = id[name];
                
                it = S00.find(x[cur] + y[cur]);
                S00.erase(it);
                
                it = S01.find(x[cur] - y[cur]);
                S01.erase(it);
                
                --sz;
            }
            
            if(sz == 0) puts("-1");
            else{
                int mn00 = *S00.begin();
                int mx00 = *S00.rbegin();
                int mn01 = *S01.begin();
                int mx01 = *S01.rbegin();
                
                printf("%d\n",max(mx00 - mn00,mx01 - mn01));
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
