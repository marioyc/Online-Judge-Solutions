#include <cstdio>

using namespace std;

#define MOD 5000000

int dp[51][100001];

void update(int bit[], int idx, int val){
    for(int x = idx;x <= 100000;x += x & -x){
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
    
    int ans = 0;
    
    for(int i = 0,x;i < N;++i){
        scanf("%d",&x);
        
        for(int k = K;k > 1;--k)
            update(dp[k],x + 1,query(dp[k - 1],x));
        
        update(dp[1],x + 1,1);
    }
    
    printf("%d\n",query(dp[K],100000));
    
    return 0;
}
