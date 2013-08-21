#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int x,y,z,k;
    
    scanf("%d %d %d %d",&x,&y,&z,&k);
    
    long long ans = 0;
    
    for(int i = 0;i < x && i <= k;++i){
        long long aux = 0;
        k -= i;
        
        int c1 = (k + 1) / 2;
        if(c1 < y && (k - c1) < z) aux = max(aux,(long long)(1 + c1) * (1 + k - c1));
        
        int c2 = (k + 2) / 2;
        if(c2 < y && (k - c2) < z) aux = max(aux,(long long)(1 + c2) * (1 + k - c2));
        
        if(k >= y) aux = max(aux,(long long)y * min(z,1 + k - (y - 1)));
        
        if(k >= z) aux = max(aux,(long long)z * min(y,1 + k - (z - 1)));
        
        k += i;
        aux *= 1 + i;
        ans = max(ans,aux);
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
