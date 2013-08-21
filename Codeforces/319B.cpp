#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    int r[n],kill[2][n],m = 0;
    
    for(int i = 0;i < n;++i){
        r[i] = i + 1;
        if(i + 1 < n && a[i] > a[i + 1]) kill[0][m++] = i;
    }
    
    int cur = 0,ans = 0;
    
    while(m > 0){
        int m2 = 0;
        
        for(int i = m - 1;i >= 0;--i){
            int x = kill[cur][i];
            r[x] = r[ r[x] ];
            if(r[x] < n && a[x] > a[ r[x] ]) kill[cur ^ 1][m2++] = x;
        }
        
        cur ^= 1;
        m = m2;
        reverse(kill[cur],kill[cur] + m);
        ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
