#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool notprime[10000000];
vector< pair<int, long long> > f;

int main(){
    for(int i = 2;i < 10000000;++i){
        if(!notprime[i]){
            if(i > 2)
                for(int aux = 2;i <= 10000000 / aux;aux <<= 1)
                    f.push_back(make_pair(aux * i,(2 * aux - 1) * (i + 1) - 2 * aux * i));
            
            if(i <= 3162)
                for(int j = i * i;j < 10000000;j += i)
                    notprime[j] = true;
        }
    }
    
    sort(f.begin(),f.end());
    int m = f.size();
    
    for(int i = 1;i < m;++i)
        f[i].second += f[i - 1].second;
    
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        int lo = 0,hi = m - 1,mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(f[mi].first > n) hi = mi - 1;
            else lo = mi;
        }
        
        printf("%d %lld\n",n,f[lo].second);
    }
}
