#include <cstdio>

using namespace std;

int n,a[100000],st[100000];

int main(){
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        bool ok = true;
        int pos = 0,pos2 = 0,sz = 0;
        
        while(ok && pos < n){
            if(sz > 0 && st[sz - 1] == a[pos]){
                --sz;
                ++pos;
            }else if(pos2 < n){
                st[sz] = ++pos2;
                ++sz;
            }else ok = false;
        }
        
        puts(ok? "Not a proof" : "Cheater");
    }
    
    return 0;
}
