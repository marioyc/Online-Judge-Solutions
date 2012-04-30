#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    int a[n],b[m];
    
    for(int i = 0;i < n;++i) scanf("%d",&a[i]);
    for(int i = 0;i < m;++i) scanf("%d",&b[i]);
    sort(a,a + n);
    sort(b,b + m);
    
    int sza = 1;
    
    for(int i = 1;i < n;++i)
        if(a[i] != a[sza - 1])
            a[sza++] = a[i];
    
    int szb = 1;
    
    for(int i = 1;i < m;++i)
        if(b[i] != b[szb - 1])
            b[szb++] = b[i];
    
    int ans = 0;
    
    for(int i = 0,j = 0;i < sza;++i){
        while(j < szb && b[j] < a[i]) ++j;
        
        if(j < szb && b[j] == a[i]) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
