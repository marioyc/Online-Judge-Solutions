#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXVAL 1000000000000LL

struct sol{
    long long n;
    int kr,r;
    
    sol(){}
    
    sol(long long _n, int _kr, int _r):
        n(_n), kr(_kr), r(_r){}
    
    bool operator < (sol X)const{
        if(n != X.n) return n < X.n;
        if(kr != X.kr) return kr < X.kr;
        return r < X.r;
    }
};

vector<sol> v;
int m;

void solve(long long n, long long &kr, int &r){
    int lo = 0,hi = m - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(v[mi].n < n) lo = mi + 1;
        else hi = mi;
    }
    
    if(v[lo].n == n){
        kr = v[lo].kr;
        r = v[lo].r;
    }else{
        kr = n;
        r = 1;
    }
}

int main(){
    for(int k = 2;k <= 1000000;++k){
        int r = 1;
        long long x = k;
        
        while(x <= (MAXVAL - k) / k){
            x = k * x + k;
            ++r;
            v.push_back(sol(x,k * r,r));
        }
    }
    
    sort(v.begin(),v.end());
    m = v.size();
    
    long long n,kr1,kr2;
    int r1,r2;
    
    while(scanf("%lld",&n) == 1){
        solve(n,kr1,r1);
        solve(n - 1,kr2,r2);
        
        if(kr2 < kr1 || (kr2 == kr1 && r2 < r1)){
            kr1 = kr2;
            r1 = r2;
        }
        
        printf("%d %lld\n",r1,kr1 / r1);
    }
    
    return 0;
}
