#include <cstdio>
#include <cstring>

using namespace std;

int sz = 0,a[1000000];
bool valid[1000000];

int main(){
    memset(valid,true,sizeof valid);
    
    for(int i = 2;i <= 100;++i){
        int c = i * i * i;
        
        for(int j = c;j <= 1000000;j += c)
            valid[j] = false;
    }
    
    for(int i = 1;i <= 1000000;++i)
        if(valid[i])
            a[sz++] = i;
    
    int tc = 1,T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        int lo = 0,hi = sz - 1,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if(a[mi] < n) lo = mi + 1;
            else hi = mi;
        }
        
        printf("Case %d: ",tc++);
        
        if(a[lo] != n) printf("Not Cube Free\n");
        else printf("%d\n",lo + 1);
    }
    
    return 0;
}
