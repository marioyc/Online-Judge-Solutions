#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,k;
    
    scanf("%d %d %d",&n,&m,&k);
    
    int a[n],b[m];
    
    for(int i = 0;i < n;++i) scanf("%d",&a[i]);
    for(int i = 0;i < m;++i) scanf("%d",&b[i]);
    sort(a,a + n);
    sort(b,b + m);
    
    bool found = false;
    
    for(int i = 0,j = 0;i < n || j < m;){
        int cur;
        
        if(i < n && j < m) cur = max(a[n - 1 - i],b[m - 1 - j]);
        else if(i < n) cur = a[n - 1 - i];
        else cur = b[m - 1 - j];
        
        while(i < n && a[n - 1 - i] == cur) ++i;
        while(j < m && b[m - 1 - j] == cur) ++j;
        
        if(i > j) found = true;
    }
    
    puts(found? "YES" : "NO");
    
    return 0;
}
