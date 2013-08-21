#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int t[n],c[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d %d",&t[i],&c[i]);
    
    for(int i = 0;i < n;++i)
        for(int j = i + 1;j < n;++j)
            if(t[j] < t[i]){
                swap(t[i],t[j]);
                swap(c[i],c[j]);
            }
    
    int last = 0,maxq = 0,sz = 0,prev = 0;
    
    for(int i = 0,j = 0;i < n;){
        int e = i;
        int cur = t[i];
        
        sz = max(0,sz - (cur - prev));
        
        while(e < n && t[e] == cur){
            sz += c[e];
            ++e;
        }
        
        maxq = max(maxq,sz);
        if(sz) last = cur + sz;
        
        i = e;
        prev = cur;
    }
    
    printf("%d %d\n",last,maxq);
    
    return 0;
}
