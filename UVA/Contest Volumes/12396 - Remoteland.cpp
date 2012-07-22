#include <cstdio>
#include <vector>

using namespace std;

#define MOD 1000000007

bool noprime[5000000];
vector<int> p;

long long pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    p.push_back(2);
    
    for(int i = 3;i < 5000000;i += 2){
        if(!noprime[i]){
            p.push_back(i);
            
            if(i <= 2236)
                for(int j = i * i;j < 5000000;j += i)
                    noprime[j] = true;
        }
    }
    
    int n,m = p.size();
    long long ans;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        ans = 1;
        
        for(int i = 0;i < m && p[i] <= (n >> 1);++i){
            int aux = n,d = p[i],exp = 0;
            
            while(aux){
                exp += aux / d;
                aux /= d;
            }
            
            if(exp & 1) --exp;
            ans = ans * pow(d,exp) % MOD;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
