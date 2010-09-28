#include <cstdio>
#include <cstring>

using namespace std;

#define min(x,y) (x)<(y)? (x):(y)
#define abs(x) (x)<0? -(x):(x)

int main(){
    int n,w[100],W = 0;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;++i){
        scanf("%d",&w[i]);
        W += w[i];
    }
    
    bool possible[n+1][W];
    memset(possible,false,sizeof(possible));
    possible[0][0] = true;
    
    for(int i=0;i<n;++i)
        for(int j=n/2-1;j>=0;--j)
            for(int k=W;k>=w[i];--k)
                possible[j+1][k] |= possible[j][k-w[i]];
    
    int min_diff = W;
    
    for(int j=0;j<=W;++j)
        if(possible[n/2][j])
            min_diff = min(min_diff,abs(W-2*j));
    
    printf("%d %d\n",(W-min_diff)/2,(W+min_diff)/2);
    
    return 0;
}
