#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,a[10];
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        sort(a,a + n);
        
        bool win = false;
        
        for(int i = 0;i < n;){
            int e = i;
            
            while(e < n && a[e] == a[i]) ++e;
            
            if((e - i) & 1) win = true;
            i = e;
        }
        
        puts(win? "1" : "0");
    }
    
    return 0;
}
