#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define MOD 14348907

int n;
pair<int, int> memo[47][24 * 9];
bool done[47][24 * 9];

int mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

pair<int, int> solve(int pos, int sum){
    if(sum < 0) return make_pair(0,0);
    if(pos == n) return make_pair(sum == 0? 1 : 0,0);
    
    pair<int, int> &ret = memo[pos][sum];
    
    if(!done[pos][sum]){
        done[pos][sum] = true;
        ret = make_pair(0,0);
        
        for(int i = (pos == 0? 1 : 0);i <= 9;++i){
            int sum2 = sum;
            if(pos < (n + 1) / 2) sum2 += i;
            if(n - 1 - pos < (n + 1) / 2) sum2 -= i;
            
            pair<int, int> aux = solve(pos + 1,sum2);
            
            ret.first = (ret.first + aux.first) % MOD;
            ret.second = (ret.second + (long long)aux.first * mod_pow(10,n - 1 - pos) * i + aux.second) % MOD;
        }
    }
    
    return ret;
}

int main(){
    int ans = 0;
    
    for(int i = 1;i <= 47;++i){
        memset(done,false,sizeof done);
        n = i;
        ans = (ans + solve(0,0).second) % MOD;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
