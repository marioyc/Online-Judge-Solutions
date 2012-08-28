#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int T,n;
    pair<int,int> P[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0,l,r;i < n;++i){
            scanf("%d %d",&l,&r);
            P[i] = make_pair(r,l);
        }
        
        sort(P,P + n);
        
        int ans = 0,e = -1;
        
        for(int i = 0;i < n;++i){
            if(P[i].second >= e){
                e = P[i].first;
                ++ans;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
