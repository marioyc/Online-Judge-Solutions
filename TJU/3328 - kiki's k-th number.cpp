#include <cstdio>
#include <cstring>

using namespace std;

int bit[100000],cont[100000];

int query(int x){
    int ret = 0;
    
    for(int idx = x;idx > 0;idx -= idx & -idx)
        ret += bit[idx];
    
    return ret;
}

void update(int x, int val){
    for(int idx = x;idx < 100000;idx += idx & -idx)
        bit[idx] += val;
}

int main(){
    int Q,p,e,a,k,n;
    
    while(scanf("%d",&Q) == 1){
        memset(bit,0,sizeof bit);
        memset(cont,0,sizeof cont);
        n = 0;
        
        while(Q--){
            scanf("%d",&p);
            
            if(p == 0){
                scanf("%d",&e);
                
                ++cont[e]; ++n;
                update(e,1);
            }
            
            if(p == 1){
                scanf("%d",&e);
                
                if(cont[e] == 0) puts("No Elment!");
                else{
                    --cont[e]; --n;
                    update(e,-1);
                }
            }
            
            if(p == 2){
                scanf("%d %d",&a,&k);
                
                k += query(a);
                
                if(k > n) puts("Not Find!");
                else{
                    int lo = 1,hi = 100000,mi;
                    
                    while(lo < hi){
                        mi = (lo + hi) >> 1;
                        
                        if(query(mi) < k) lo = mi + 1;
                        else hi = mi;
                    }
                    
                    printf("%d\n",lo);
                }
            }
        }
    }
    
    return 0;
}
