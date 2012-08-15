#include <cstdio>
#include <vector>

using namespace std;

bool is_prime(int n){
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 2;i <= n / i;++i)
        if(n % i == 0) return false;
    
    return true;
}

vector<int> p;
long long n,best,ans;

void solve(int pos, long long x, long long div, int last){
    if(div > best || (div == best && x < ans)){
        best = div;
        ans = x;
    }
    
    if(pos == 35) return;
    
    for(int i = 1;i <= last && x <= n / p[pos];++i){
        x *= p[pos];
        solve(pos + 1,x,div * (i + 1),i);
    }
}

int main(){
    for(int i = 2;p.size() < 35;++i)
        if(is_prime(i))
            p.push_back(i);
    
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&n);
        
        best = 1;
        ans = 1;
        
        solve(0,1,1,60);
        
        printf("%lld %lld\n",ans,best);
    }
    
    return 0;
}
