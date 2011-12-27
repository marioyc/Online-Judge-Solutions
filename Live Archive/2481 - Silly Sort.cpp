#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int tc = 1,N,a[1000],b[1000];
    bool done[1000];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i) scanf("%d",&a[i]);
        for(int i = 0;i < N;++i) b[i] = i;
        
        for(int i = 0;i < N;++i)
            for(int j = i + 1;j < N;++j)
                if(a[ b[i] ] > a[ b[j] ])
                    swap(b[i],b[j]);
        
        int mn = a[0];
        
        for(int i = 1;i < N;++i)
            mn = min(mn,a[i]);
        
        memset(done,false,sizeof done);
        
        int ans = 0;
        
        for(int i = 0;i < N;++i){
            if(!done[i]){
                int mn2 = a[i];
                int ind = i;
                int sum = 0;
                int sz = 0;
                
                while(!done[ind]){
                    done[ind] = true;
                    sum += a[ind];
                    mn2 = min(mn2,a[ind]);
                    ind = b[ind];
                    ++sz;
                }
                
                ans += min(sum + (sz - 2) * mn2,sum + mn2 + (sz + 1) * mn);
            }
        }
        
        printf("Case %d: %d\n\n",tc++,ans);
    }
    
    return 0;
}
