#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 200000

pair<int, int> P[MAXN];
int n,inc[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int bit[MAXN + 1];

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret = max(ret,bit[x]);
    
    return ret;
}

void update(int idx, int val){
    for(int x = idx;x <= n;x += x & -x)
        bit[x] = max(bit[x],val);
}

int main(){
    int TC;
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i){
            scanf("%d",&P[i].first);
            P[i].second = i;
        }
        
        sort(P,P + n);
        
        for(int i = 0,j = 0;i < n;++j){
            int e = i;
            
            while(e < n && P[e].first == P[i].first) ++e;
            
            for(int k = i;k < e;++k) P[k].first = j;
            
            i = e;
        }
        
        sort(P,P + n,cmp);
        
        int ans = 0;
        inc[0] = 1;
        
        for(int i = 1;i < n;++i){
            if(P[i].first > P[i - 1].first) inc[i] = inc[i - 1] + 1;
            else inc[i] = 1;
        }
        
        memset(bit,0,sizeof bit);
        
        for(int i = n - 1,inc2;i >= 0;--i){
            if(i < n - 1 && P[i].first < P[i + 1].first) ++inc2;
            else inc2 = 1;
            
            update(n - P[i].first,inc2);
            ans = max(ans,inc[i] + query(n - 1 - P[i].first));
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
