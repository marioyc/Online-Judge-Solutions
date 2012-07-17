#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 5000000

int a[10000],b[10000];
int dp[51][10001];
bool found[10001];

void update(int bit[], int idx, int val){
    val %= MOD;
    if(val < 0) val += MOD;
    
    for(int x = idx;x <= 10000;x += x & -x){
        bit[x] += val;
        if(bit[x] >= MOD) bit[x] -= MOD;
    }
}

int query(int bit[], int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x){
        ret += bit[x];
        if(ret >= MOD) ret -= MOD;
    }
    
    return ret;
}

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    
    sort(b,b + N);
    int m = unique(b,b + N) - b;
    
    for(int i = 0;i < N;++i){
        int x = 1 + (lower_bound(b,b + m,a[i]) - b);
        
        for(int k = K;k > 1;--k)
            update(dp[k],x,query(dp[k - 1],x - 1) - query(dp[k],x) + query(dp[k],x - 1));
        
        if(!found[x]){
            update(dp[1],x,1);
            found[x] = true;
        }
    }
    
    printf("%d\n",query(dp[K],10000));
    
    return 0;
}
