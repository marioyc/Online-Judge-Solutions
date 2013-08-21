#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    char s[m + 1];
    int row[n];
    
    for(int i = 0;i < n;++i){
        scanf("%s",s);
        row[i] = 0;
        
        for(int j = 0;j < m;++j)
            if(s[j] == '*')
                row[i] |= (1 << j);
    }
    
    int ans = n,mask[(1 << n)];
    mask[0] = 0;
    
    for(int i = 1;i < (1 << n);++i){
        int lb = __builtin_ctz(i);
        mask[i] = (mask[i ^ (1 << lb)] | row[lb]);
        ans = min(ans,max(n - __builtin_popcount(i),__builtin_popcount(mask[i])));
    }
    
    printf("%d\n",ans);
    
    return 0;
}
