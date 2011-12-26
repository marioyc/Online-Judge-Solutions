#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int main(){
    vector<int> v;
    
    for(int i = 1;i * i < 10000000;++i)
        for(int j = 1;j * j * j * j < 10000000;++j)
            if(is_prime(i * i + j * j * j * j))
                v.push_back(i * i + j * j * j * j);
    
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    
    int T,n,sz = v.size();
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        if(n == 1) printf("0\n");
        else{
            int lo = 0,hi = sz - 1,mi;
            
            while(lo < hi){
                mi = (lo + hi + 1) / 2;
                
                if(v[mi] > n) hi = mi - 1;
                else lo = mi;
            }
            
            printf("%d\n",lo + 1);
        }
    }
    
    return 0;
}
