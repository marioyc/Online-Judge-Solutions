#include <cstdio>

using namespace std;

#define MAXN 100000

int n,l[MAXN],r[MAXN];

int main(){
    scanf("%d",&n);
    
    int ans = 0;
    
    for(int i = 0;i < n;++i){
        scanf("%d %d",&l[i],&r[i]);
        
        if(l[i] <= l[ans] && r[ans] <= r[i]) ans = i;
    }
    
    for(int i = 0;i < n;++i)
        if(!(l[ans] <= l[i] && r[i] <= r[ans])) ans = -2;
    
    printf("%d\n",ans + 1);
    
    return 0;
}
