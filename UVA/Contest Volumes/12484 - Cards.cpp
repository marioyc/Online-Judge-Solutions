#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10000];
long long memo[2][10000];

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        for(int p = 1,len = 1;len <= N;++len,p ^= 1){
            for(int i = 0,j = len - 1;i + len <= N;++i,++j){
                if(p == 0){
                    memo[0][i] = max(a[i] + memo[1][i + 1],memo[1][i] + a[j]);
                }else{
                    if(len == 1) memo[1][i] = 0;
                    else memo[1][i] = min(memo[0][i + 1],memo[0][i]);
                }
            }
        }
        
        printf("%lld\n",memo[0][0]);
    }
    
    return 0;
}
