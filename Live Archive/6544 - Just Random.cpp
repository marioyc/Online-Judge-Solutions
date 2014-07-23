#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long solve(int l, int r, int l2, int r2){
    l = max(l,l2);
    r = min(r,r2);
    return (l <= r? r - l + 1 : 0);
}

int main(){
    int T;
    long long a,b,c,d,p,m,k1,k2;
    vector<long long> l,r,t,l2,r2,t2;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&p,&m);
        
        a += p - m;
        b += p - m;
        
        long long aux = (d + p - 1) / p;
        c -= aux * p;
        d -= aux * p;
        swap(c,d);
        c = -c; d = -d;
        
        l.clear(); r.clear(); t.clear();
        l2.clear(); r2.clear(); t2.clear();
        
        k1 = (b - a + 1) / p;
        k2 = (d - c + 1) / p;
        
        l.push_back(0); r.push_back(p - 1); t.push_back(k1);
        l2.push_back(0); r2.push_back(p - 1); t2.push_back(k2);
        
        if((b - a + 1) % p != 0){
            if(b % p >= a % p){
                l.push_back(a % p);
                r.push_back(b % p);
                t.push_back(1);
            }else{
                l.push_back(a % p);
                r.push_back(p - 1);
                t.push_back(1);
                
                l.push_back(0);
                r.push_back(b % p);
                t.push_back(1);
            }
        }
        
        if((d - c + 1) % p != 0){
            if(d % p >= c % p){
                l2.push_back(c % p);
                r2.push_back(d % p);
                t2.push_back(1);
            }else{
                l2.push_back(c % p);
                r2.push_back(p - 1);
                t2.push_back(1);
                
                l2.push_back(0);
                r2.push_back(d % p);
                t2.push_back(1);
            }
        }
        
        long long num = 0,den = (b - a + 1) * (d - c + 1);
        
        for(int i = l.size() - 1;i >= 0;--i)
            for(int j = l2.size() - 1;j >= 0;--j)
                num += solve(l[i],r[i],l2[j],r2[j]) * t[i] * t2[j];
        
        long long g = __gcd(num,den);
        num /= g; den /= g;
        
        printf("Case #%d: %lld/%lld\n",tc,num,den);
    }
    
    return 0;
}
