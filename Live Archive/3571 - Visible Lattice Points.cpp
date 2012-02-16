#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,M[1001];
    
    M[0] = 1;
    
    for(int j = 1;j <= 1000;++j){
        M[j] = M[j - 1];
        
        for(int i = 1;i <= j;++i)
            if(__gcd(i,j) == 1)
                M[j] += 2;
    }
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        
        printf("%d %d %d\n",tc,n,M[n]);
    }
    
    return 0;
}
