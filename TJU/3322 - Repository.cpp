#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define B 31
#define MOD 1000000009

map< pair<long long, int>, int > M;

int main(){
    int N,Q;
    char s[21];
    
    scanf("%d",&N);
    
    while(N--){
        scanf("%s",s);
        
        int L = strlen(s);
        vector< pair<long long, int> > v;
        
        for(int j = 0;j < L;++j){
            long long h = 0;
            
            for(int k = j;k < L;++k){
                h = (h * B + s[k] - 'a') % MOD;
                v.push_back(make_pair(h,k - j + 1));
            }
        }
        
        sort(v.begin(),v.end());
        
        int m = v.size();
        
        for(int j = 0;j < m;){
            int e = j;
            
            while(e < m && v[e] == v[j]) ++e;
            
            ++M[ v[j] ];
            
            j = e;
        }
    }
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%s",s);
        
        int L = strlen(s);
        long long h = 0;
        
        for(int i = 0;i < L;++i)
            h = (h * B + s[i] - 'a') % MOD;
        
        printf("%d\n",M[ make_pair(h,L) ]);
    }
    
    return 0;
}
