#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int b[] = {3,5,17,257,65537},bk[] = {1,2,4,8,16};
map<long long, int> get_mask;
int sum[(1 << 5)];

long long MAX_VAL = (1LL << 32) - 1;

void gen(int pos, long long n, int k, int mask){
    if(pos == 5){
        get_mask[n] = mask;
        sum[mask] = k;
        return;
    }
    
    gen(pos + 1,n,k,mask);
    
    if(n <= MAX_VAL / b[pos])
        gen(pos + 1,n * b[pos],k + bk[pos],(mask | (1 << pos)));
}

long long odd[30];
int e2[30];
int memo[30][931][(1 << 5)];

int solve(int pos, int sum2, int mask){
    if(pos == -1) return (sum2 == 0? 0 : sum2 - 1);
    
    int &ret = memo[pos][sum2][mask];
    
    if(ret == -1){
        ret = solve(pos - 1,sum2,mask);
        
        int mask2 = get_mask[ odd[pos] ];
        
        if((mask & mask2) == 0){
            int aux = sum[mask2] + solve(pos - 1,sum2 + e2[pos],mask | mask2);
            ret = max(ret,aux);
        }
    }
    
    return ret;
}

int main(){
    gen(0,1,0,0);
    
    int n;
    
    while(scanf("%d",&n) == 1){
        int n2 = 0;
        
        for(int i = 0;i < n;++i){
            scanf("%lld",&odd[i]);
            e2[i] = 0;
            
            while(odd[i] % 2 == 0){
                odd[i] >>= 1;
                ++e2[i];
            }
            
            if(get_mask.find(odd[i]) != get_mask.end()){
                odd[n2] = odd[i];
                e2[n2] = e2[i];
                ++n2;
            }
        }
        
        if(n2 == 0) printf("No Solution\n");
        else{
            memset(memo,-1,sizeof memo);
            printf("%d\n",solve(n2 - 1,0,0));
        }
    }
    
    return 0;
}
