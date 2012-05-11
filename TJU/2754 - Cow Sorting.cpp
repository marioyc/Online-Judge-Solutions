#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100000

int N,a[MAXN],nxt[MAXN];
pair<int, int> b[MAXN];
bool done[MAXN];

int main(){
    scanf("%d",&N);
    
    long long ans = 0;
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a[i]);
        b[i] = make_pair(a[i],i);
        ans += a[i];
    }
    
    sort(b,b + N);
    
    for(int i = 0;i < N;++i)
        nxt[ b[i].second ] = i;
    
    memset(done,false,sizeof done);
    int mn = b[0].first;
    
    for(int i = 0;i < N;++i){
        if(!done[i]){
            int pos = i,mn2 = a[i],n = 0;
            
            while(!done[pos]){
                done[pos] = true;
                mn2 = min(mn2,a[pos]);
                ++n;
                
                pos = nxt[pos];
            }
            
            ans += min((long long)(n - 2) * mn2,(long long)(n + 1) * mn + mn2);
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
