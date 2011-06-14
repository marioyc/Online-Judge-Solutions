#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,ind;
    
    scanf("%d %d",&n,&ind);
    
    int st[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&st[i]);
    
    int x = st[ind];
    
    sort(st,st+n);
    
    for(int i = 0;i < n;++i)
        if(st[i] == x)
            ind = i+1;
    
    int log = 0;
    
    while((1 << log) <= n) ++log;
    --log;
    
    printf("%d ",(ind != n)? 0 : log);
    
    log = 0;
    
    while((1 << log) <= ind) ++log;
    --log;
    
    printf("%d\n",log);
    
    return 0;
}
