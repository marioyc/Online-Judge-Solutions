#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,L,l[100000];
    
    scanf("%d %d",&n,&L);
    for(int i=0;i<n;++i) scanf("%d",&l[i]);
    sort(l,l+n);
    
    int ans = 0,s = 0,e = n-1;
    
    while(s<=e){
        if(s<e && l[s]+l[e]<=L) ++s,--e;
        else --e;
        ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
