#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100000

int a[MAXN];
int dp[MAXN + 1];

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    int sz = (int)floor(sqrt(N));
    
    vector<int> q;
    q.push_back(N);
    
    dp[N] = 0;
    
    for(int i = N - 1;i >= 0;--i){
        for(int j = q.size() - 1;j >= 0;--j)
            if(a[ q[j] ] == a[i])
                q.erase(q.begin() + j);
        
        dp[i] = N;
        
        for(int j = q.size() - 1;j >= 0;--j)
            dp[i] = min(dp[i],(j + 1) * (j + 1) + dp[ q[j] ]);
        
        q.insert(q.begin(),i);
        if(q.size() > sz) q.pop_back();
    }
    
    printf("%d\n",dp[0]);
    
    return 0;
}
