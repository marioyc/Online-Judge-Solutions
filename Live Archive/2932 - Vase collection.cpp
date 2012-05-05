#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
long long mask[36];

bool search(int pos, int k, int have, long long m){
    if(have > 0 && __builtin_popcount(m) < k) return false;
    if(have == k) return true;
    if(pos == v.size()) return false;
    
    bool ok = false;
    
    if(have == 0) ok = search(pos + 1,k,1,mask[ v[pos] ]);
    else ok = search(pos + 1,k,have + 1,m & mask[ v[pos] ]);
    
    ok = ok || search(pos + 1,k,have,m);
    
    return ok;
}

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        memset(mask,0,sizeof mask);
        v.clear();
        
        for(int i = 0,x,y;i < n;++i){
            scanf("%d %d",&x,&y);
            --x; --y;
            v.push_back(x);
            mask[x] |= (1LL << y);
        }
        
        sort(v.begin(),v.end());
        
        int sz = 1;
        
        for(int i = 1;i < v.size();++i)
            if(v[i] != v[sz - 1])
                v[sz++] = v[i];
        
        while(v.size() > sz) v.pop_back();
        
        int lo = 0,hi = 10,mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(search(0,mi,0,0LL)) lo = mi;
            else hi = mi - 1;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
