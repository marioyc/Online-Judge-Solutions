#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int rmq[18][200000];

int solve(int l, int r){
    int lg = 0;
    while((1 << lg) <= (r - l + 1)) ++lg;
    --lg;
    
    return max(rmq[lg][l],rmq[lg][r + 1 - (1 << lg)]);
}

int main(){
    while(true){
        scanf("%d %d",&n,&k);
        if(n < 0) break;
        
        for(int i = 0;i < n;++i)
            scanf("%d",&rmq[0][i]);
        
        for(int i = 1;(1 << i) <= n;++i){
            int sz1 = (1 << i),sz2 = (1 << (i - 1));
            
            for(int j = 0;j + sz1 <= n;++j)
                rmq[i][j] = max(rmq[i - 1][j],rmq[i - 1][j + sz2]);
        }
        
        int ans = -1;
        
        for(int m = 1;m <= n && ans == -1;){
            int sz = n / m,sum = 0;
            
            for(int i = 1,pos = 0;pos + sz <= n;pos += sz,++i){
                sum += solve(pos,pos + sz - 1);
                
                if(i >= m && sum > k){
                    ans = i;
                    break;
                }
            }
            
            m = n / sz + 1;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
